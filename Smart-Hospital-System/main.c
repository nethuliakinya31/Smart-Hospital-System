#include <stdio.h>
#define MAX_PATIENTS 100

//step 5-Add patient data structures
char patientName[MAX_PATIENTS][50];
int patientAge[MAX_PATIENTS];
int urgencyLevel[MAX_PATIENTS];
int specialtyID[MAX_PATIENTS];
int admittedToWard[MAX_PATIENTS];
int patientWard[MAX_PATIENTS];
int wardID[MAX_PATIENTS];
int daysAdmitted[MAX_PATIENTS];
int bedID[MAX_PATIENTS];//this stores which bed was assigned to each patient.
int waitingTime[MAX_PATIENTS];

int specialtyQueueCount[4]={0};

double emergencySurcharge[MAX_PATIENTS];
double baseFee[MAX_PATIENTS];
double wardCost[MAX_PATIENTS];
double grossBill[MAX_PATIENTS];
double ageDiscount[MAX_PATIENTS];
double finalBill[MAX_PATIENTS];




int patientCount=0;

//step 4
int bedOccupancy[4][20] ={0};

//step 3
//pre-defined lookup tables for doctor specialties data.
const char *specialtyNames[] = {"General Practice(OPD)",
                                 "Paediatrics",
                                 "Cardiology",
                                 "Neurology"};

const double consultationFees[] = {1500.00,
                                  2500.00,
                                  4500.00,
                                  5000.00};

const int consultationTimes[] = {15,20,30,30};

const int dailyPatientCapacities[] = {30,20,12,10};

//pre-defined lookup tables for hospital wards data.
 const char *wardNames[] = {"General Ward",
                            "Paediatric Ward",
                            "Surgical Ward",
                            "ICU(Intensive Care Unit)"};

const double dailyBedRate[] = {3000.00,
                               6000.00,
                               12000.00,
                               25000.00};

const int wardCapacity[] = {20,10,10,5};



//This follows the requirement to use custom functions.

void initializeBeds()
{
  for(int i=0;i<4;i++){
    for(int j=0;j<20;j++){
        bedOccupancy[i][j]=0;
    }
  }
}

int calculateWaitingTime(int specialty){

    int queueCount = specialtyQueueCount[specialty - 1];

    int averageTime = consultationTimes[specialty - 1];

    return queueCount * averageTime;
}

//function - Calculate emergency surcharge
double calculateEmergencySurcharge(int urgency,double baseFee){

     if (urgency==1){
        return 0;
     }
     else if(urgency==2){
        return baseFee*0.20;
     }
     else{
        return baseFee*0.50;
     }
}
//calculate ward cost
double calculateWardCost(int ward,int days){
       if (ward==0){
        return 0;
       }
       return dailyBedRate[ward-1]*days;
}
//calculate gross bill
double calculateGrossBill(double baseFee,double surcharge,double wardCost){
     return baseFee + surcharge + wardCost;

}




//age subsidy calculation
double calculateAgeDiscount(int age,double grossBill){
    if(age<5 || age>65){
        return grossBill*0.15;
    }
    else{
        return 0;
    }

}
//step 6:
//Add patient registration-Putting the information of patients
//(patient's name, age, urgency level,admission status,if admitted to ward wardID,
//number of days admitted.) into the arrays.

//Function 1-register patients
void registerPatient(){

    printf("\n---Patient Registration ---\n");

//Patient's name
    printf("Enter patient name:");
    scanf(" %[^\n]",patientName[patientCount]);

//Patient's age
    printf("Enter patient age:");
    scanf("%d",&patientAge[patientCount]);

//step 7:Input validation
    while(patientAge[patientCount] < 0){

        printf("Invalid age. Please enter a valid age: ");
        scanf("%d", &patientAge[patientCount]);
    }

//Urgency Level
    printf("Enter urgency level(1=Normal, 2=Urgent, 3=Critical):");
    scanf("%d",&urgencyLevel[patientCount]);

     while (urgencyLevel[patientCount] < 1 ||
           urgencyLevel[patientCount] > 3)
    {

        printf("Invalid urgency level. Please enter a valid urgency level: ");
        scanf("%d", &urgencyLevel[patientCount]);
    }




//Specialty ID
    printf("Enter specialtyID(1-4):");
    scanf("%d",&specialtyID[patientCount]);

    while (specialtyID[patientCount]<1 || specialtyID[patientCount]>4 ){

        printf("Invalid specialty ID. Please enter a valid specialty ID: ");
        scanf("%d", &specialtyID[patientCount]);
    }

    baseFee[patientCount] = consultationFees[specialtyID[patientCount] - 1];

    emergencySurcharge[patientCount] =
    calculateEmergencySurcharge(urgencyLevel[patientCount],
                                baseFee[patientCount]);


//step 9- waiting time calculation
    waitingTime[patientCount]=calculateWaitingTime(specialtyID[patientCount]);
    specialtyQueueCount[specialtyID[patientCount]-1]++;

//Ward admission status
    printf("Is the patient admitted to a ward?(1=Yes,0=No): ");
    scanf("%d",&admittedToWard[patientCount]);

    while (admittedToWard[patientCount]!=0 && admittedToWard[patientCount]!=1){

        printf("Invalid choice. Please enter 1 for Yes or 0 for No: ");
        scanf("%d", &admittedToWard[patientCount]);
    }

    if (admittedToWard[patientCount] == 1){

        printf("Enter ward ID (1-4) :");
        scanf("%d",&wardID[patientCount]);

        while (wardID[patientCount]<1 || wardID[patientCount]>4){

            printf("Invalid ward ID. Please enter a valid ward ID:");
            scanf("%d",&wardID[patientCount]);
        }

        printf("Enter number of days admitted :");
        scanf("%d",&daysAdmitted[patientCount]);

        while (daysAdmitted[patientCount] <=0){

            printf("Invalid number of days.Please enter a positive number:");
            scanf("%d",&daysAdmitted[patientCount]);
        }
    }
    else
        {

        wardID[patientCount]= 0;
        daysAdmitted[patientCount] = 0;
    }
//Ward cost calculation
    wardCost[patientCount] =calculateWardCost(wardID[patientCount],
                      daysAdmitted[patientCount]);
//Gross bill calculation
    grossBill[patientCount] =calculateGrossBill(baseFee[patientCount],
                       emergencySurcharge[patientCount],
                       wardCost[patientCount]);
//Age discount calculation
    ageDiscount[patientCount] =calculateAgeDiscount(patientAge[patientCount],
                         grossBill[patientCount]);
//Calculate final bill
    finalBill[patientCount] =
    grossBill[patientCount] - ageDiscount[patientCount];


        printf("\nPatient registered successfully!\n");

        printf("Estimated waiting time: %d minutes\n",waitingTime[patientCount-1]);
        printf("Base consultation fee:%.2f\n",baseFee[patientCount]);
        printf("Emergency surcharge:%.2f\n",emergencySurcharge[patientCount]);
        printf("Ward cost: %.2f\n",wardCost[patientCount]);
        printf("Gross bill: %.2f\n",grossBill[patientCount]);
        printf("Age discount:%.2f\n",ageDiscount[patientCount]);
        printf("Final payable amount:%.2f\n",finalBill[patientCount]);
    patientCount++;
    }




//Function 2 - bedAllocation

void bedAllocation(int patientCount)
{
    int patientID;

    printf("\n---Bed Allocation---\n");

    printf("Enter patient number: ");
    scanf("%d", &patientID);

    if (patientID < 1 || patientID > patientCount)
    {
        printf("Invalid patient number.\n");
        return;
    }

    if (bedID[patientID - 1] != 0)
    {
        printf("A bed has already been allocated to this patient.\n");
        printf("Bed number: %d\n", bedID[patientID - 1]);
        return;
    }

    int patientWardID = wardID[patientID-1];


//search for an available bed
    for (int i = 0; i < wardCapacity[patientWardID - 1]; i++)
    {
        if (bedOccupancy[patientWardID - 1][i] == 0)
        {
            bedOccupancy[patientWardID - 1][i] = 1;

            bedID[patientID - 1] = i + 1;

            printf("Bed allocated successfully.\n");

            printf("Patient: %s\n",
                   patientName[patientID - 1]);

            printf("Ward: %s\n",
                   wardNames[patientWardID - 1]);

            printf("Bed Number: %d\n",
                   bedID[patientID - 1]);
            return;
        }
    }

    printf("No available beds in this ward.\n");
}


//Display priority order of patients
void displayPriorityPatients(){

      int order[MAX_PATIENTS];
      //store patient indexes
      for (int i=0;i<patientCount;i++){
        order[i]=i;
      }

      //Bubble sort according to urgency
      for(int i=0; i<patientCount ; i++){
        for (int j=0;j<patientCount - i - 1 ;j++){
            if (urgencyLevel[order[j]]<urgencyLevel[order[j+1]]){
                int temp=order[j];
                order[j]=order[j+1];
                order[j+1]=temp;
            }
        }
    }
//Display patients in priority order -Requirement 4
printf("\n--- Patient Priority List ---\n");

for (int i = 0; i < patientCount; i++)
    {
        int index = order[i];

        printf("Patient %d : %s | Urgency Level: %d\n",index + 1,patientName[index],urgencyLevel[index]);
    }
}


//Display the admission bill-Requirement 5


void displayAdmissionBill(int patientID){

    if (patientID < 1 || patientID > patientCount)
    {
        printf("Invalid patient number.\n");
        return;
    }

    int index = patientID - 1;

    printf("\n====================================================\n");
    printf("        SMART HOSPITAL ADMISSION & BILL\n");
    printf("----------------------------------------------------\n");

    printf("Patient ID               : PAT-%04d\n", 1000 + patientID);
    printf("Patient Name             : %s\n", patientName[index]);

    printf("Age                      : %d Years", patientAge[index]);

    if (patientAge[index] < 5 || patientAge[index] > 65)
    {
        printf(" (15%% Subsidy Eligible)");
    }

    printf("\n");

    printf("Specialty                : %s\n",
           specialtyNames[specialtyID[index] - 1]);

    if (admittedToWard[index] == 1)
    {
        printf("Assigned Ward        : %s (Bed #%02d)\n",
               wardNames[wardID[index] - 1],
               bedID[index]);
    }
    else
    {
        printf("Assigned Ward           : Outpatient / OPD\n");
    }

    if (urgencyLevel[index] == 1)
    {
        printf("Urgency Level           : Level 1 (Normal)\n");
    }
    else if (urgencyLevel[index] == 2)
    {
        printf("Urgency Level        : Level 2 (Urgent)\n");
    }
    else
    {
        printf("Urgency Level        : Level 3 (Critical)\n");
    }

    printf("----------------------------------------------------\n");

    printf("Base Consultation Fee    : LKR %.2f\n",
           baseFee[index]);

    if (urgencyLevel[index] == 2)
    {
        printf("Emergency Surcharge     : LKR %.2f (20%%)\n",
               emergencySurcharge[index]);
    }
    else if (urgencyLevel[index] == 3)
    {
        printf("Emergency Surcharge     : LKR %.2f (50%%)\n",
               emergencySurcharge[index]);
    }
    else
    {
        printf("Emergency Surcharge     : LKR %.2f (0%%)\n",
               emergencySurcharge[index]);
    }

    printf("Ward Stay Cost (%d Days) : LKR %.2f\n",
           daysAdmitted[index],
           wardCost[index]);

    printf("----------------------------------------------------\n");

    printf("Gross Total Bill         : LKR %.2f\n",
           grossBill[index]);

    if (patientAge[index] < 5 || patientAge[index] > 65)
    {
        printf("Age Subsidy Discount    : LKR -%.2f (15%%)\n",
               ageDiscount[index]);
    }
    else
    {
        printf("Age Subsidy Discount : LKR -%.2f (0%%)\n",
               ageDiscount[index]);
    }

    printf("----------------------------------------------------\n");

    printf("Final Payable Amount     : LKR %.2f\n",
           finalBill[index]);

    printf("Estimated Waiting Time   : %d mins\n",
           waitingTime[index]);

    printf("====================================================\n");
}



// Requirement 6 - Performance Reports and Analytics
void generateReport()
{
    int normalCount = 0;
    int urgentCount = 0;
    int criticalCount = 0;

    double totalRevenue = 0.0;
    double totalDiscount = 0.0;

    int highestPatient = 0;
    double highestBill = 0.0;

    // Check if there are no patients
    if (patientCount == 0)
    {
        printf("\nNo patients have been registered yet.\n");
        return;
    }

    // Calculate patient statistics
    for (int i = 0; i < patientCount; i++)
    {
        // Count patients according to urgency
        if (urgencyLevel[i] == 1)
        {
            normalCount++;
        }
        else if (urgencyLevel[i] == 2)
        {
            urgentCount++;
        }
        else if (urgencyLevel[i] == 3)
        {
            criticalCount++;
        }

        // Calculate total revenue
        totalRevenue += finalBill[i];

        // Calculate total discounts
        totalDiscount += ageDiscount[i];

        // Find highest-paying patient
        if (finalBill[i] > highestBill)
        {
            highestBill = finalBill[i];
            highestPatient = i;
        }
    }

    printf("\n====================================================\n");
    printf("        SMART HOSPITAL PERFORMANCE REPORT\n");
    printf("====================================================\n");

    // 1. Total patients and urgency levels
    printf("\nPATIENT SUMMARY\n");
    printf("----------------------------------------------------\n");
    printf("Total Patients Registered : %d\n", patientCount);
    printf("Normal Patients           : %d\n", normalCount);
    printf("Urgent Patients           : %d\n", urgentCount);
    printf("Critical Patients         : %d\n", criticalCount);

    // 2. Revenue and discounts
    printf("\nREVENUE SUMMARY\n");
    printf("----------------------------------------------------\n");
    printf("Total Revenue             : LKR %.2f\n", totalRevenue);
    printf("Total Discounts Granted   : LKR %.2f\n", totalDiscount);

    // 3. Bed occupancy
    printf("\nBED OCCUPANCY\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < 4; i++)
    {
        int occupiedBeds = 0;

        for (int j = 0; j < wardCapacity[i]; j++)
        {
            if (bedOccupancy[i][j] == 1)
            {
                occupiedBeds++;
            }
        }

        double occupancyPercentage =
            ((double)occupiedBeds / wardCapacity[i]) * 100;

        printf("%-25s : %d/%d beds (%.2f%%)\n",
               wardNames[i],
               occupiedBeds,
               wardCapacity[i],
               occupancyPercentage);
    }

    // 4. Highest-paying patient
    printf("\nHIGHEST-PAYING PATIENT\n");
    printf("----------------------------------------------------\n");
    printf("Patient Name              : %s\n",
           patientName[highestPatient]);

    printf("Patient ID                : PAT-%04d\n",
           1000 + highestPatient + 1);

    printf("Total Bill                : LKR %.2f\n",
           highestBill);

    printf("====================================================\n");
}




int main()
{
    initializeBeds();


    //step 2-Add main menu and navigation.
    int choice=0;

    printf("SMART HOSPITAL & RESOURCE ALLOCATION SYSTEM\n");

    while(choice !=6){

        printf("\n");
        printf("1.Register Patient\n");
        printf("2.Allocate Bed\n");
        printf("3.Display Priority of Patients\n");
        printf("4.Display admission bill\n");
        printf("5.Generate Report\n");
        printf("6.Exit\n");

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                registerPatient();
                break;
            case 2:
                bedAllocation(patientCount);
                break;
            case 3:
                displayPriorityPatients();
                break;
            case 4:
                  {
                      int patientID;

                      printf("Enter patient number: ");
                      scanf("%d", &patientID);

                      displayAdmissionBill(patientID);

                      break;
                 }

            case 5:
                generateReport();
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");

        }

    }


    return 0;
}

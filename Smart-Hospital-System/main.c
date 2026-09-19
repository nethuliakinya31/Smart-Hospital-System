#include <stdio.h>
#define MAX_PATIENTS 100

//step 5-Add patient data structures
char patientName[MAX_PATIENTS][50];
int patientAge[MAX_PATIENTS];
int urgencyLevel[MAX_PATIENTS];
int specialtyID[MAX_PATIENTS];
int admittedToWard[MAX_PATIENTS];
int wardID[MAX_PATIENTS];
int daysAdmitted[MAX_PATIENTS];

int patientCount=0;



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
                               12,000.00,
                               25,000.00};

const int totalBedCapacity[] = {20,10,10,05};
//step 4
int bedOccupancy[4][20];


//This follows the requirement to use custom functions.

void initializeBeds()
{
  for(int i=0;i<4;i++){
    for(int j=0;j<20;j++){
        bedOccupancy[i][j]=0;
    }
  }
}

//step 6:
//Add patient registration-Putting the information of patients
//(patient's name, age, urgency level,admission status,if admitted to ward wardID,
//number of days admitted.) into the arrays.


void registerPatient(){

    printf("\n---Patient Registration ---\n");

    printf("Enter patient name:");
    scanf(" %[^\n]",patientName[patientCount]);

    printf("Enter patient age:");
    scanf("%d",&patientAge[patientCount]);

    printf("Enter urgency level(1=Normal, 2=Urgent, 3=Critical):");
    scanf("%d",&urgencyLevel[patientCount]);

    printf("Enter specialtyID(1-4):");
    scanf("%d",&specialtyID[patientCount]);

    printf("Is the patient admitted to a ward?(1=Yes,0=No): ");
    scanf("%d",&admittedToWard[patientCount]);

    if (admittedToWard[patientCount] == 1){

        printf("Enter ward ID (1-4) :");
        scanf("%d",&wardID[patientCount]);

        printf("Enter number of days admitted :");
        scanf("%d",&daysAdmitted[patientCount]);

    }
    else
        {

        wardID[patientCount]= 0;
        daysAdmitted[patientCount] = 0;
    }
        patientCount++;

        printf("\nPatient registered successfully!\n");
    }




int main()
{
    initializeBeds();
    registerPatient();

    //step 2-Add main menu and navigation.
    int choice=0;

    printf("SMART HOSPITAL & RESOURCE ALLOCATION SYSTEM\n");

    while(choice !=9){

        printf("\n");
        printf("1.Register Patient\n");
        printf("2.Display Patients\n");
        printf("3.Search Patient\n");
        printf("4.Allocate Bed\n");
        printf("5.Calculate Bill\n");
        printf("6.Priority Queue\n");
        printf("7.Reports\n");
        printf("8.Save Data\n");
        printf("9.Exit\n");

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
                registerPatient();
                break;
            case 2:
                printf("Display Patient selected.\n");
                break;
            case 3:
                printf("Search Patient selected.\n");
                break;
            case 4:
                printf("Allocate Bed selected.\n");
                break;
            case 5:
                printf("Calculate Bill selected.\n");
                break;
            case 6:
                printf("Priority Queue selected.\n");
                break;
            case 7:
                printf("Reports selected.\n");
                break;
            case 8:
                printf("Save data selected.\n");
                break;
            case 9:
                printf("Exiting the program selected.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");

        }

    }


    return 0;
}

#include <stdio.h>


int main()
{
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
                printf("Register Patient selected.\n");
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

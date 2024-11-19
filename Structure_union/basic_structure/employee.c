// Define an array of structures to store multiple employee records and print them.

#include <stdio.h>

struct employee
{
    char name[50];
    int id;
    float salary;
};

int main()
{
    // Declare an array of structures to store employee records
    struct employee multiple[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Enter the employee information %d:\n", i + 1);
        
        printf("Enter the name:");
        //Read string with space
        scanf(" %[^\n]%*c", multiple[i].name);

        printf("Enter the id:");
        scanf("%d",&multiple[i].id);

        printf("Enter the salary:");
        scanf("%f",&multiple[i].salary);

        printf("\n");
    }

    // Print the employee records
    printf("Employee records: ");
    for(i = 0; i < 3; i++)
    {
        printf("Employee %d:\n", i + 1);
        printf("Employee name:%s\n", multiple[i].name);
        printf("Employee id:%d\n", multiple[i].id);
        printf("Employee salary:%.1f\n", multiple[i].salary);
    }

    
}
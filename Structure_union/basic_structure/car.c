// Write a program that stores car details and displays the most expensive car.

#include <stdio.h>

struct cardetails
{
    char name[50];
    char model[50];
    float price;
}car;

void displaymostexpensivecar(struct cardetails car[], int n)
{
    int index = 0;
    int i;
    for(i = 1; i < n; i++)
    {
        if (car[i].price > car[index].price)
        {
            index = i;
        }
    }

    printf("Most Expensive car:\n");
    printf("Name: %s\n", car[index].name);
    printf("Model: %s\n", car[index].model);
    printf("Price: %f\n", car[index].price);
}

int main()
{
    int n, i;

    printf("Enter the number of cars: ");
    scanf("%d", &n);

    struct cardetails car[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for car %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", car[i].name); // No & needed for array
        printf("Model: ");
        scanf("%s", car[i].model); // No & needed for array
        printf("Price: ");
        scanf("%f", &car[i].price); // Use &cars[i].price
    }

    displaymostexpensivecar(car, n);
    
}
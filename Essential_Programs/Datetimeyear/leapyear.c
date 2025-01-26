// Leap year using if and else statement

#include <stdio.h>
int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    if (year != 100)
    {
        if (year % 4 == 0)
        {
            printf("Leap year\n");
        }
        else
        {
            printf("Year is not a Leap year\n");
        }
    }
    else
    {
        if (year % 400 == 0)
        {
            printf("Leap year\n");
        }
        else
        {
            printf("Year is not a Leap year\n");
        }
    }
}
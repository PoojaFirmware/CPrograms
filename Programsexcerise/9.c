// Program to count digits in a number

#include<stdio.h>
int main()
{
    int number, count = 0;
    printf("Enter the number: ");
    scanf("%d", &number);
    if (number == 0)
    {
        count = 1;
    }
    else 
    {
        if (number < 0)
        {
            number = -number;
        }
        //Count the digits
        while (number != 0)
        {
            number /= 10; // remove the last digits
            count++; // increment the digits count
        }
    }
    printf("the digits count is: %d\n", count);
    return 0;
}
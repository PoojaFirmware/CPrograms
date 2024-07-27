// Print numbers from 1 to 10 using while loop, for loop, do while loop

#include<stdio.h>
int main()
{
    int i = 1;

    // Using while loop
    while(i <= 10)
    {
        printf("%d\n", i);
        i++;
    }

    // Using for loop
    for(i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }

    // Using do while loop
    do 
    {
        printf("%d\n", i);
        i++;
    }while(i <= 10);

    return 0;
}
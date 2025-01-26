//Factorial program using Iterative apporach & Recursive apporach

#include <stdio.h>
int Factorial_Iterative(int n)
{
    int result = 1, i;
    // Both ways we can do we will get same result and Looping upwards was the best apporach.
    for(i = 1; i <= n; i++) // Looping Upwards (from 1 to n)
    // for(i = n; i >= 1; i--) // Looping Downwards (from n to 1)
    {
        result *= i;
    }
    return result;
}

int Factorial_recursive(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * Factorial_recursive(n - 1);
    }
}


int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("Factorial in negative is undefined");
    }
    else
    {
        int res = Factorial_Iterative(num);
        printf("Factorial in Iterative apporach: %d\n", res);

        int res1 = Factorial_recursive(num);
        printf("Factorial in recursive apporach: %d\n", res1);

    }
}


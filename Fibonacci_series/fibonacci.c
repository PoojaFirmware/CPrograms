//Fibonacci series program

#include <stdio.h>
int Fibonacci(int n)
{
    int t1 = 0, t2 = 1, nextterm;
    printf("Fibonacci series: %d %d\n", t1, t2);

    for(int i = 1; i <= n-2; i++)
    {
        nextterm = t1 + t2;
        printf("%d", nextterm);
        t1 = t2;
        t2 = nextterm;
    }
    printf("\n");
}

int main()
{
    int number;
    printf("Enter the number");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Enter the positive number");
    }
    else if (number == 0)
    {
        printf("Fibonacci series: 0\n");
    }
    else
    {
        Fibonacci(number);
    }
}

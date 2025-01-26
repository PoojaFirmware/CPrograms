// Check 2 numbers are equal or not Program

#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);
    if (a == b)
    {
        printf("The numbers are equal: %d %d\n", a, b);
    }
    else 
    {
        printf("The numbers are not equal: %d %d\n", a, b);
    }
}

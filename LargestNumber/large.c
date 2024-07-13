// Largest Number among 3 numbers Program using if and else statment only.

#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter the number: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b)
    {
        if (a >= c)
        {
            printf("a is largest = %d\n", a);
        }
        else
        {
            printf("c is largest = %d\n", c);
        }
    }
    else
    {
        if (b >= c)
        {
            printf("b is largest = %d\n", b);
        }
        else 
        {   
            printf("c is largest = %d\n", c);
        }
    }

}

// Largest Number among 3 numbers Program using Logical AND statement.

#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter the number: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >= c)
    {
        printf("a is largest = %d\n", a);
    }
    else if (b >= a && b >= c)  
    {
        printf("b is largest = %d\n", b);
    }
    else 
    {   
        printf("c is largest = %d\n", c);
    }
}

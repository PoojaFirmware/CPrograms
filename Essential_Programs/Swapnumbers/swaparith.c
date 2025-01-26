// Swap 2 numbers Program using arithmetic variables without using temporary variables

#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("The a value is: %d\n", a);
    printf("The b value is: %d\n", b);
    return 0;
}

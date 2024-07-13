// Swap 2 numbers Program using temporary variables

#include <stdio.h>
int main()
{
    int a, b, temp;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);
    temp = a;
    a = b;
    b = temp;
    printf("The a value is: %d\n", a);
    printf("The b value is: %d\n", b);
    return 0;
}

// Accept 2 numbers, if the 1st number is greater than 2nd number then print the difference else print 
// sum of 2 sum numbers using ternary operator.

#include <stdio.h>
int main()
{
    int x, y, c, d;
    printf("Enter the 2 numbers: ");
    scanf("%d %d", &x, &y);
    c = x + y;
    d = x - y;
    x > y ? printf("difference: %d\n", d): printf("sum: %d\n", c);
}
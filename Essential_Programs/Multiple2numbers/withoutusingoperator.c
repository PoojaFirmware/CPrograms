// Multiply 2 operators without using *.

#include <stdio.h>
int main()
{
    // int sum = 0, a, b, i , j, term;
    // printf("Enter the 2 numbers: ");
    // scanf("%d %d", &a, &b);
    // for(i = 1; i <= b; i++)
    // {
    //     sum += term;
    //     term += i;
    // }
    // printf("the sum is: %d\n", sum);
    int a, res = 0, b, i;
    printf("Enter the 2 numbers: ");
    scanf("%d %d", &a, &b);
    for(i = 0; i < b; i++)
    {
        res += a;
    }
    printf("the res is: %d\n", res);
}
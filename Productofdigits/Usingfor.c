// Product of digits Program using for statement

#include <stdio.h>
int main()
{
    //Inialitize the value of n and product to 1.
    int n = 0, product = 1, rem;
    printf("Enter the number: ");
    scanf("%d", &n);

    // n /= 10 is used as increment in for loop.
    for(; n > 0; n /= 10)
    {
        rem = n % 10;
        product *= rem;
    }
    printf("The sum of digits is = %d\n", product);
    return 0;
}

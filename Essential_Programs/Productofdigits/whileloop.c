// Product of digits Program using while loop

#include <stdio.h>
int main()
{
    //Inialitize the value of n and product to 0 and 1.
    int n = 0, product = 1, rem;
    printf("Enter the number: ");
    scanf("%d", &n);
    while (n > 0)
    {
        rem = n % 10;
        product *= rem;
        n /= 10; //Used as a increment form
    }
    printf("The sum of digits is = %d\n", product);
    return 0;
}

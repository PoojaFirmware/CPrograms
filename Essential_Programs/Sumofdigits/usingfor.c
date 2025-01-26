// Sum of digits Program using for statement

#include <stdio.h>
int main()
{
    //Inialitize the value of n and sum to 0.
    int n = 0, sum = 0, rem;
    printf("Enter the number: ");
    scanf("%d", &n);

    // n /= 10 is used as increment in for loop.
    for(; n > 0; n /= 10)
    {
        rem = n % 10;
        sum += rem;
    }
    printf("The sum of digits is = %d\n", sum);
    return 0;
}

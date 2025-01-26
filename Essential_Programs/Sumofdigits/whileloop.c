// Sum of digits Program using while loop

#include <stdio.h>
int main()
{
    //Inialitize the value of n and sum to 0.
    int n = 0, sum = 0, rem;
    printf("Enter the number: ");
    scanf("%d", &n);
    while (n > 0)
    {
        rem = n % 10;
        sum += rem;
        n /= 10; //Used as a increment form
    }
    printf("The sum of digits is = %d\n", sum);
    return 0;
}

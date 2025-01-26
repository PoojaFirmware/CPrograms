// Sum of digits Program using for statement and temporary variable
// Using a for loop we need to make a copy of n (temporary variable) then we can
// do the sum of digits 

#include <stdio.h>
int main()
{
    //Inialitize the value of n and sum to 0.
    int n = 0, sum = 0, rem;
    printf("Enter the number: ");
    scanf("%d", &n);

    // Make a copy of n into a temporary variable. 
    int temp = n;

    // temp /= 10 is used as increment in for loop.
    for(; temp > 0; temp /= 10)
    {
        rem = temp % 10;
        sum += rem;
    }
    printf("The sum of digits is = %d\n", sum);
    return 0;
}

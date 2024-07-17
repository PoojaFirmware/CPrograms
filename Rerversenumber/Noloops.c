// Reverse of number without using loops, strings, recursion, functions.

#include <stdio.h>
int main()
{
    int num, rev;
    printf("Enter the number: ");
    scanf("%d", &num);

    if (num < 100000 || num > 999999)
    {
        printf("Check the number of 6 digits\n");
        return 1;
    }

    // Extract and rearrange the digits 
    int digit1 = num % 10;
    int digit2 = (num / 10) % 10;
    int digit3 = (num / 100) % 10;
    int digit4 = (num / 1000) % 10;
    int digit5 = (num / 10000) % 10;
    int digit6 = (num / 100000) % 10;

    // Construct in reverse order
    rev = digit1 * 100000 +
          digit2 * 10000 +
          digit3 * 1000 +
          digit4 * 100 +
          digit5 * 10 +
          digit6;

    printf("Rerverse of a number is %d\n", rev);
    return 0;
}
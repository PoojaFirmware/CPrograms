// Reverse of number using while loop

#include <stdio.h>
int main()
{
    int num, rev = 0, rem;
    printf("Enter the number: ");
    scanf("%d", &num);
    while (num > 0)
    {
        rem = num % 10; // Extract the last digit
        rev = rev * 10 + rem; // Append the digit to rev
        num /= 10; // Remove the last digit from num
    }
    printf("Rerverse of a number is %d\n", rev);
    return 0;
}
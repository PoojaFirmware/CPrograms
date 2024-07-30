// The sum of series upto n times - 1 + 2 + 4 + 7 + 11..............

#include <stdio.h>
int main()
{
    int sum = 0, n, term = 1, i;
    printf("Enter the numbers: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        sum += term;
        printf("Sum is: %d\t", sum);
        term += i;
        printf("Term is: %d\n", term);
    }
    printf("Total is: %d\n", sum);
}
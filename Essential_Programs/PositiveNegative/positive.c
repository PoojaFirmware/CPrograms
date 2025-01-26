// Positive Negative integers program

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n >= 0)
    {
        printf("The positive number is : %d\n", n);
    }
    else
    {
        printf("The Negative number is : %d\n", n);
    }
}
// Write a program to accept any number and print the value of reimander after dividing it by 3.

#include <stdio.h>
int main()
{
    int x, reimander;
    printf("Enter the numbers: ");
    scanf("%d", &x);

    reimander = x % 3;
    printf("The reimander of number = %d\n", reimander);
}
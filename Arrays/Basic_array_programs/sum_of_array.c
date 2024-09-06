// Program for add to an array

#include <stdio.h>
int main()
{
    int arr[5], i;
    int sum = 0;
    for (i = 0; i < 5; i++)
    {
        printf("The value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf ("Sum = %d\n", sum);
    printf("\n");
}
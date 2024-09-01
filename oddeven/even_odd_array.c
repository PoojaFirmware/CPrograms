// Program for even and odd to an array

#include <stdio.h>
int main()
{
    int arr[5], i;
    int even_count = 0, odd_count = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Enter the value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
        {
            printf("even\n");
            even_count++;
        }
        else
        {
            printf("odd\n");
            odd_count++;
        }
    }
    printf ("even = %d\n", even_count);
    printf ("odd = %d\n", odd_count);
}
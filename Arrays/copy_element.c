// Program for copy the element from a to b using a array

#include <stdio.h>
int main()
{
    int a[5] = { 1, 2, 3, 4, 5};
    int b[5], i;

    // Copy the elements a to b 
    for(i = 0; i < 5; i++)
    {
        b[i] = a[i];
    }
    printf("The array elements are: \n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", b[i]);
    }
    printf("\n");
}
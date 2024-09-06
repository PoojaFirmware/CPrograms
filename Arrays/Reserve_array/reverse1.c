#include <stdio.h>
void resverse(int arr[], int n)
{
    int i, temp;
    for (i = 0; i < n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array\n");
    printarray(arr, n);

    resverse(arr, n);

    printf("Resverse array\n");
    printarray(arr, n);

    return 0;
}
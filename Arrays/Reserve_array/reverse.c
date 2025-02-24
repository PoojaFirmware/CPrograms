#include <stdio.h>
void reverse(int arr[], int n)
{
    int temp;
    int start = 0;
    int end = n - 1;

    while(start < end)
    {
        //swap function
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        //Move the pointer to center
        start++;
        end--;
    }
}

void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array\n");
    printarray(arr, n);

    reverse(arr, n);

    printf("Resverse array\n");
    printarray(arr, n);

    return 0;
}
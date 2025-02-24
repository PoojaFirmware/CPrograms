// **Shift Array Elements Left or Right** : Implement a function to shift array elements left or right by a given number of positions.

#include <stdio.h>

void shiftLeft(int arr[], int n, int pos)
{
    pos = pos % n; // Handle cases where pos > n
    for(int i = 0; i < pos; i++)
    {
        int first = arr[0]; // store first element 
        for(int j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1]; // shift left
        }
        arr[n - 1] = first; // Move first element to the end 
    }
}


void shiftRight(int arr[], int n, int pos)
{
    pos = pos % n; // Handle cases where pos > n
    for(int i = 0; i < pos; i++)
    {
        int last = arr[n - 1]; // store last element 
        for(int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1]; // shift right
        }
        arr[0] = last; // Move last element to the front
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int shift = 2; // Number of positions to shift

    printf("Original Array: ");
    printArray(arr, n);

    // Left Shift
    shiftLeft(arr, n, shift);
    printf("Array after left shift by %d positions: ", shift);
    printArray(arr, n);

    // Resetting the array
    int arr2[] = {1, 2, 3, 4, 5};

    // Right Shift
    shiftRight(arr2, n, shift);
    printf("Array after right shift by %d positions: ", shift);
    printArray(arr2, n);

    return 0;
}
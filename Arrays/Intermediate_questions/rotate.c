// Rotate an Array by 'n' Positions : Write a function to rotate an array by 'n' positions.

// Algorithm (Left Rotation by n Positions)
// 1. Store the first n elements in a temporary array.
// 2. Shift the remaining elements of the array to the left.
// 3. Copy the stored elements back to the end of the array.

#include <stdio.h>

void rotateArray(int arr[], int size, int n)
{
    n = n % size; // Handle cases where n > sizes
    int temp[n]; // temporary array to store first n elements

    // Store first n elements in temporary array
    for(int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    // Shift the remaining elements in temporary array
    for(int i = 0; i < size - n; i++)
    {
        arr[i] = arr[i + n];
    }

    // Copy the stored elements back to the end
    for(int i = 0; i < n; i++)
    {
        arr[size - n + i] = temp[i];
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 2; // Number of positions to rotate

    printf("Original Array: ");
    printArray(arr, size);

    rotateArray(arr, size, n);

    printf("Rotated Array: ");
    printArray(arr, size);

    return 0;
}
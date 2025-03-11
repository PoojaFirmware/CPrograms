// Split an Array into Two Halves: Write a function to split an array into two halves.

#include <stdio.h>

void splitArray(int arr[], int size)
{
    int mid = (size + 1)/ 2;
    int firsthalf[mid], secondhalf[size - mid];

    // Copy elements to first half
    for(int i = 0; i < mid; i++)
    {
        firsthalf[i] = arr[i];
    }

    // Copy elements to second half
    for(int i = mid, j = 0; i <size; i++, j++)
    {
        secondhalf[j] = arr[i];
    }

    // Print first half
    printf("First half: ");
    for(int i = 0; i < mid; i++)
    {
        printf("%d ", firsthalf[i]);
    }
    printf("\n");

    // Print second half
    printf("Second Half: ");
    for (int i = 0; i < size - mid; i++) {
        printf("%d ", secondhalf[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  // Example with an odd-sized array
    int size = sizeof(arr) / sizeof(arr[0]);

    splitArray(arr, size);

    return 0;
}

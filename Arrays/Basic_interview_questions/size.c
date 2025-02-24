// **Determine the Size of an Array in C** : Implement a function to determine the size of an array in C.

// In C, the size of an array cannot be determined inside a function if passed as an argument 
// because the array decays into a pointer. However, we can determine the size in main() before passing it to a function.

#include <stdio.h>

void printArray(int arr[], int size)
{
    printf("Size of the array: %d elements\n", size);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6}; 
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    printArray(arr, size);

    return 0;
}
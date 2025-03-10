// Remove Duplicate Elements from an Array : Implement a function to remove duplicate elements from an array.

// Algorithm:
// 1. Sort the array (if not already sorted) to bring duplicates together.
// 2. Use a new index to store unique elements.
// 3. Iterate through the array, comparing each element with the previous one.
// 4. Store only distinct elements in the array.
// 5. Return the new length of the modified array.

#include <stdio.h>

int removeDuplicates(int arr[], int n)
{
    if(n == 0 || n == 1)
    {
        return n; // If array has 0 or 1 element, no duplicates exists
    }

    int uniqueIndex = 0; // Index to store unique elements

    // Traverse the array and store only unique elements
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[uniqueIndex])
        {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    return uniqueIndex + 1; // return the new size of the array
}

int main() 
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5, 6, 6}; // Sorted input array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Remove duplicates and get the new size
    int newSize = removeDuplicates(arr, n);

    // Print the array after removing duplicates
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

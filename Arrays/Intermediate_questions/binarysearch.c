// Binary Search on a Sorted Array: Implement a function to perform binary search on a sorted array.

// Function to perform Binary Search on a sorted array
// 1. Find the middle element of the array.
// 2. If the middle element is the target, return its index.
// 3. If the target is smaller, search in the left half.
// 4. If the target is larger, search in the right half.
// 5. Repeat the process until the search space is exhausted.
// 6. If the target is not found, return -1.

#include <stdio.h>

int binarysearch(int arr[], int left, int right, int target)
{
    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if(arr[mid] == target)
        {
            return mid;
        }

        // If target is smaller, search in the left half
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        // If target is larger, search in the right half
        else 
        {
            left = mid + 1;
        }
    }
    // Target not found
    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarysearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
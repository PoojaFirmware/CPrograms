// Merge Two Sorted Arrays: Write a function to merge two sorted arrays into a single sorted array.

#include <stdio.h>

void mergesortedarrays(int arr1[], int size1, int arr2[], int size2, int merged[])
{
    int i = 0, j = 0, k = 0;

    // Merge both arrays by comparing elements
    while(i < size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while(i < size1)
    {
        merged[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while(j < size2)
    {
        merged[k++] = arr2[j++];
    }
}

int main()
{
    // Sorted input arrays
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[size1 + size2]; // Resultant merged array

    // Merge the two sorted arrays
    mergesortedarrays(arr1, size1, arr2, size2, merged);

    // Print the merged sorted array
    printf("Merged Sorted Array: ");
    for (int i = 0; i < size1 + size2; i++) 
    {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
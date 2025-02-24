// **Find the Maximum and Minimum Elements** : Write a function to find the maximum and minimum elements in an array.

#include <stdio.h>

void Findmaxmin(int arr[], int size, int *min, int *max)
{
    *min = *max = arr[0]; // Initialize min and max with the first elements

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < *min)
        {
            *min = arr[i]; // Update min if a smaller element is found
        }
        if(arr[i] > *max)
        {
            *max = arr[i]; // Update max if a greater element is found
        }
    }
}

int main()
{
    int arr[] = {3, 1, 6, 7, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    // Call the function to find min and max
    Findmaxmin(arr, size, &min, &max);

    // Print the results
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
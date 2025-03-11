// Find the Second Largest Number: Implement a function to find the second largest number in an array.

#include <stdio.h>
#include <limits.h> // For INT_MIN

void findsecondLargest(int arr[], int size)
{
    if(size < 2)
    {
        printf("Array must have at least two elements\n");
        return;
    }

    int largest = INT_MIN, secondLargest = INT_MIN;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) 
    {
        printf("No second largest element found (all elements are the same).\n");
    } 
    else 
    {
        printf("The second largest number is: %d\n", secondLargest);
    }
}

int main() 
{
    int arr[] = {10, 20, 4, 45, 99, 99, 32, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    findsecondLargest(arr, size);

    return 0;
}
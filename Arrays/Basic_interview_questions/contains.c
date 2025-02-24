// **Check if an Array Contains a Specific Value** : Write a function to check if an array contains a particular value.

#include <stdio.h>

// To check if an array contains a specific value 
int contains(int arr[], int size, int values)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == values)
        {
            return 1; // Value found
        }
    }
    return 0; // Value not found
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 30;

    if(contains(arr, size, value))
    {
        printf("Value %d is present in the array\n", value);
    }
    else
    {
        printf("Value %d is present in the array\n", value);
    }
}
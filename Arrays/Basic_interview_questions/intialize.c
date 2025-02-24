// 1. **Initialize an Array with Given Values** : Write a function to initialize an array with specified values.

#include <stdio.h>

// To initialize an array with a given values
void initaliseArray(int arr[], int size, int value)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}

// print the array
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
    int size = 5; // size of the array
    int arr[size]; // declare array
    int value = 10; // value of initialize

    initaliseArray(arr, size, value);

    printf("initaliseArray: ");
    printArray(arr,size);
}
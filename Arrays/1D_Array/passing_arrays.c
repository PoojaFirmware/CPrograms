// Passing Individual array elements to a function &
// Passing Whole array elements to a function


// Passing Individual array elements to a function
// Explaination: We can pass Individual array elements as arguments. When we pass
// Individual elements of an array to function we are passing the values at those positions in the array
// Like passing other variables.

// Passing the whole Array to a function
// When passing the entire array, you're passing a pointer to the first element of the array. 
// This allows function to access all the elements of the array.

#include <stdio.h>

// function to print Individual elements
void printElements(int elements)
{
    printf("Elements: %d\n", elements);
}

// function to print the entire array
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Elements of an array %d: %d\n", i, arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    // Passing Individual elements
    for (int i = 0; i < 5; i++)
    {
        printElements(arr[i]); // Pass each elements to the function
    }

    // Passing the whole array
    printArray(arr, 5); //Passes the whole array to the function
}




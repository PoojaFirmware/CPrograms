// Count Occurrences of Each Element : Write a function to count the occurrences of each element in an array.

// Approach:
// 1. Use an array to store input elements.
// 2. Use another array (visited) to keep track of counted elements.
// 3. Iterate through the array and count occurrences of each element.

#include <stdio.h>

void countOccurrences(int arr[], int size)
{
    int i, j;
    // Array to mark counted elements
    int visited[size];

    for (i = 0; i < size; i++)
    {
        visited[i] = 0; // Initialize visited array
    }

    printf("Element | Count\n");
    printf("----------------\n");

    for (i = 0; i < size; i++)
    {
        if (visited[i] == 1)
        {
            continue; // Skip already counted elements
        }

        int count = 1; // Initialize count

        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1; // Mark duplicate elements
            }
        }
        printf("   %d    |   %d\n", arr[i], count);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 2, 3, 4, 1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    countOccurrences(arr, size);

    return 0;
}

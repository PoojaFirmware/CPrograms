#include <stdio.h>
int main()
{
    int largest, smallest, n, i;


    //Enter the elements
    printf("Enter the n elements:");
    scanf("%d", &n);

    // Declare the array after getting the size 'n'
    int arr[n];

    //Input the array elements
    printf("Enter the array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    smallest = arr[0];

    //Traverse through the elements to find the largest and smallest
    for (i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    int difference = largest - smallest;

    printf("Largest array in the elements: %d\n", largest);
    printf("difference in the largest and smallest: %d\n", difference);
    printf("Smallest array in the elements: %d\n", smallest);

}
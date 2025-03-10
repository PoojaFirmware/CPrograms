// Check if an Array is a Palindrome : Implement a function to check if an array is a palindrome.

#include <stdio.h>

int isPalindrome(int arr[], int size)
{
    int left = 0, right = size - 1;

    while(left < right)
    {
        if(arr[left] != arr[right])
        {
            return 0; //Not a palindrome
        }
        left++;
        right--;
    }
    return -1; // Palindrome
}

int main()
{
    int arr1[] = {1, 2, 3, 2, 1};
    int arr2[] = {1, 2, 3, 4, 5};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (isPalindrome(arr1, size1))
        printf("arr1 is a palindrome.\n");
    else
        printf("arr1 is not a palindrome.\n");

    if (isPalindrome(arr2, size2))
        printf("arr2 is a palindrome.\n");
    else
        printf("arr2 is not a palindrome.\n");

    return 0;
}
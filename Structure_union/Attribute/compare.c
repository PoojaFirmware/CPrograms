// Write a program to calculate the size of a structure with and without the `packed` attribute.
// **Objective**: Compare the memory size of a structure before and after applying the `packed` attribute.

#include <stdio.h>
#include <stdlib.h>

// Define a structure without using packed attribute
struct normalstruct
{
    char c; // 1 byte
    int i;  // 4 byte
    double d; // 8 byte
};

// Define a structure with using packed attribute
struct __attribute__((packed)) packedstruct
{
    char c; // 1 byte
    int i;  // 4 byte
    double d; // 8 byte
};

int main() 
{
    //  Calculate the size of the structures
    size_t normalSize = sizeof(struct normalstruct);
    size_t packedSize = sizeof(struct packedstruct);

    // Print the sizes
    printf("Size of normalStruct (without packed): %zu bytes\n", normalSize);
    printf("Size of packedStruct (with packed): %zu bytes\n", packedSize);

    return 0;
}

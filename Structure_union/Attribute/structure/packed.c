// What are structure attributes in C? Demonstrate with code how to use the `packed` attribute to eliminate padding in a structure.

// **Objective**: Understand how to eliminate padding and control memory layout.
// **Example**: `__attribute__((packed))`

#include <stdio.h>
#include <stdlib.h>

// Define a structure without using packed attribute
struct mystruct1
{
    char c; // 1 byte
    int i;  // 4 byte
    double d; // 8 byte
};

// Define a structure with using packed attribute
struct __attribute__((packed)) mystruct2
{
    char c; // 1 byte
    int i;  // 4 byte
    double d; // 8 byte
};

int main() 
{
    // Display the sizes of the structures
    printf("Size of myStruct1 without packed: %lu bytes\n", sizeof(struct mystruct1));
    printf("Size of myStruct2 with packed: %lu bytes\n", sizeof(struct mystruct2));

    return 0;
}




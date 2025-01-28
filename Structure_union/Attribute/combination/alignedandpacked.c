// Demonstrate the usage of attributes like `aligned` or `packed` in a structure that contains a union as one of its members.
// **Objective**: Show how to apply both `aligned` and `packed` in a structure that includes a union.

#include <stdio.h>
#include <stdint.h>

// Define a packed structure containing a union
struct __attribute__((__packed__)) packedstruct
{
    char c; // 1 byte
    union 
    {
        int i; // 4 bytes
        float f; // 4 bytes
    }u;
    double d; // 8 doubles
};

// Define a aligned structure with a union(16 byte aligment)
struct __attribute__((aligned(16))) AlignedStruct
{
    char c; // 1 byte
    union 
    {
        int i; // 4 bytes
        float f; // 4 bytes
    }u;
    double d; // 8 doubles
};

// Define a packed and aligned structure
struct __attribute__((packed,aligned(8))) PackedAlignedStruct
{
    char c; // 1 byte
    union 
    {
        int i; // 4 bytes
        float f; // 4 bytes
    }u;
    double d; // 8 doubles
};

int main() 
{
    // Print sizes of the structures
    printf("Size of PackedStruct: %zu bytes\n", sizeof(struct packedstruct));
    printf("Size of AlignedStruct: %zu bytes\n", sizeof(struct AlignedStruct));
    printf("Size of PackedAlignedStruct: %zu bytes\n", sizeof(struct PackedAlignedStruct));

    // Demonstrate alignment properties
    printf("\nAlignment of PackedStruct: %zu bytes\n", __alignof__(struct packedstruct));
    printf("Alignment of AlignedStruct: %zu bytes\n", __alignof__(struct AlignedStruct));
    printf("Alignment of PackedAlignedStruct: %zu bytes\n", __alignof__(struct PackedAlignedStruct));
    return 0;
}
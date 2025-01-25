// Write a program to demonstrate how attributes in unions affect memory layout and size.
// **Objective**: Investigate the size and memory layout of unions with attributes like `packed` and `aligned`.

#include <stdio.h>
#include <stdalign.h>

// Define a union with and without the packed attribute
typedef union 
{
    char a;
    int b;
    double c;
}DefaultUnion;

typedef union __attribute__((packed))
{
    char a;
    int b;
    double c;
}PackedUnion;

typedef union __attribute__((aligned(16)))
{
    char a;
    int b;
    double c;
}AligedUnion;

typedef union __attribute__((packed, aligned(16))) 
{
    char a;
    int b;
    double c;
} PackedaligedUnion;

int main()
{
    // Print sizes and alignments of the unions
    printf("DefaultUnion:\n");
    printf("  Size: %zu bytes\n", sizeof(DefaultUnion));
    printf("  Alignment: %zu bytes\n\n", alignof(DefaultUnion));

    printf("PackedUnion:\n");
    printf("  Size: %zu bytes\n", sizeof(PackedUnion));
    printf("  Alignment: %zu bytes\n\n", alignof(PackedUnion));

    printf("AlignedUnion (16-byte aligned):\n");
    printf("  Size: %zu bytes\n", sizeof(AligedUnion));
    printf("  Alignment: %zu bytes\n\n", alignof(AligedUnion));

    printf("PackedAlignedUnion (packed + 16-byte aligned):\n");
    printf("  Size: %zu bytes\n", sizeof(PackedaligedUnion));
    printf("  Alignment: %zu bytes\n\n", alignof(PackedaligedUnion));

    // Declare variables and print their memory addresses to verify layout
    DefaultUnion default_obj;
    PackedUnion packed_obj;
    AligedUnion aligned_obj;
    PackedaligedUnion packed_aligned_obj;

    printf("Memory Addresses:\n");
    printf("  DefaultUnion: %p\n", (void*)&default_obj);
    printf("  PackedUnion: %p\n", (void*)&packed_obj);
    printf("  AlignedUnion: %p\n", (void*)&aligned_obj);
    printf("  PackedAlignedUnion: %p\n", (void*)&packed_aligned_obj);

    return 0;
}
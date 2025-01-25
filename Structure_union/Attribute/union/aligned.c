// Write a program to create a union with custom alignment using the `aligned` attribute.
// - **Objective**: Control the memory alignment of union members.

#include <stdio.h>
#include <stdalign.h>

// Define a union with and without the packed attribute
typedef union 
{
    char a;
    int b;
    double c;
}DefaultUnion;

typedef union __attribute__((aligned(16)))
{
    char a;
    int b;
    double c;
}AligedUnion;

int main()
{
    // Print the sizes and alignments of the unions
    printf("Size of DefaultUnion: %zu bytes\n", sizeof(DefaultUnion));
    printf("Alignment of DefaultUnion: %zu bytes\n", alignof(DefaultUnion));
    printf("\n");

    printf("Size of AlignedUnion: %zu bytes\n", sizeof(AligedUnion));
    printf("Alignment of AlignedUnion: %zu bytes\n", alignof(AligedUnion));
    printf("\n");

    // Declare variables of both unions
    DefaultUnion default_obj;
    AligedUnion aligned_obj;

    // Print memory addresses to demonstrate alignment
    printf("Address of default_obj: %p\n", (void*)&default_obj);
    printf("Address of aligned_obj: %p\n", (void*)&aligned_obj);
    printf("\n");
    
    return 0;
}
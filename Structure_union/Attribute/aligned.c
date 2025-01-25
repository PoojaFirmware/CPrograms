// How can you align a structure to a specific byte boundary using attributes? Write a program to demonstrate using the `aligned` attribute.
// - **Objective**: Learn how to control memory alignment in structures.
// - **Example**: `__attribute__((aligned(8)))`

#include <stdio.h>
#include <stddef.h>

typedef struct __attribute__((aligned(8)))
{
    char a;
    int b;
    double c;
}Alignedstruct;

typedef struct
{
    char a;
    int b;
    double c;
}Defaultstruct;

int main()
{
    //Declare variables of the structures
    Alignedstruct aligned_obj;
    Defaultstruct default_obj;

    printf("Size of Aigned structure: %zu bytes\n", sizeof(Alignedstruct));
    printf("Alignment of AlignedStruct: %zu bytes\n", _Alignof(Alignedstruct));

    printf("Size of DefaultStruct: %zu bytes\n", sizeof(Defaultstruct));
    printf("Alignment of DefaultStruct: %zu bytes\n", _Alignof(Defaultstruct));

    // Print memory addresses to verify alignment
    printf("Address of aligned_obj: %p\n", (void*)&aligned_obj);
    printf("Address of default_obj: %p\n", (void*)&default_obj);
}

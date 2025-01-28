// Write a program to define a `packed` structure containing a union and compare its size with a non-packed version.
// **Objective**: Demonstrate the combined usage of attributes for both structures and unions.

#include <stdio.h>
#include <stdint.h>

// Define a non-packed structure containing with union
struct Nonpacked
{
    char c;
    union 
    {
        int i;
        float f;
    }u;
    double d;
};

// Define a packed structure containing a union
struct __attribute__((__packed__)) packed
{
    char c;
    union 
    {
        int i;
        float f;
    }u;
    double d;
};

int main() 
{
    // Print the sizes of both structures
    printf("Size of NonPacked structure: %zu bytes\n", sizeof(struct Nonpacked));
    printf("Size of Packed structure: %zu bytes\n", sizeof(struct packed));

    return 0;
}









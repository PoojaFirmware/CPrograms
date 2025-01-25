// What happens if you use a `transparent_union` attribute? Demonstrate its usage with an example.
// **Objective**: Understand the `transparent_union` attribute and how it affects union types.

#include <stdio.h>

typedef union __attribute__((transparent_union))
{
    int i;
    float f;
    char c;
}TransparentUnion;

void process(TransparentUnion value)
{
    printf("Recevied value:\n");

    // Access each type explicitly
    printf(" Int:%d\n", value.i);
    printf(" float:%f\n", value.f);
    printf(" char:%c\n", value.c);
}

int main() 
{
    // Call process with different types directly

    process(42);        // Pass an integer
    process(3.14f);     // Pass a float
    process('A');       // Pass a char

    return 0;
}
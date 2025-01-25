// How can you use the `packed` attribute with a union? Write code to demonstrate its effect.
// **Objective**: Apply the `packed` attribute to unions to control padding and memory usage.

#include <stdio.h>
#include <stddef.h>

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

int main()
{
    printf("Sizes of Default Union: %zu bytes\n", sizeof(DefaultUnion));
    printf("Sizes of Packed union: %zu bytes\n", sizeof(PackedUnion));

    // Declare variables of both unions
    DefaultUnion default_obj;
    PackedUnion packed_obj;

    // Access members to demonstrate usage
    default_obj.a = 'A';
    default_obj.b = 12345;
    printf("DefaultUnion - a: %c, b: %d\n", default_obj.a, default_obj.b);

    packed_obj.a = 'B';
    packed_obj.b = 67890;
    printf("PackedUnion - a: %c, b: %d\n", packed_obj.a, packed_obj.b);

    return 0;
}

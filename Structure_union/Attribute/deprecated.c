// Demonstrate with code how to use the `deprecated` attribute to mark a structure as deprecated.
// **Objective**: Mark a structure as deprecated and issue a warning when used.
// **Example**: `__attribute__((deprecated))`

#include <stdio.h>

// Marking a structure as deprecated
typedef struct __attribute__((deprecated("Use NewStruct instead.")))
{
    int a;
    float b;
}OldStruct;

// A new replacement structure
typedef struct 
{
    int a;
    double b;
}Newstruct;

int main()
{
    // Using the deprecated structure
    OldStruct old_obj; // This will trigger a complier warning
    old_obj.a = 10;
    old_obj.b = 20.5;

    printf("OldStruct - a: %d, b: %.2f\n", old_obj.a, old_obj.b);

    // Using the new structure
    Newstruct new_obj;
    new_obj.a = 15;
    new_obj.b = 25.5;

    printf("NewStruct - a: %d, b: %.2lf\n", new_obj.a, new_obj.b);

    return 0;
}

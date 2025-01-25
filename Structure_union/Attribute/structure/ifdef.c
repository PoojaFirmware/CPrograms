// Write a program to create a structure with conditional compilation using preprocessor directives (`#ifdef`) and attributes.
// **Objective**: Use conditional compilation in structures based on specific compile-time conditions.

#include <stdio.h>

// Define complie time flags
#define INCLUDE_EXTRA_FIELD
#define USE_PACKED_ATTRIBUTE

// Structure with conditional compilation
typedef struct 
{
    int id;
    char name[20];


#ifdef INCLUDE_EXTRA_FIELD
    float extra_data;
#endif

#ifdef USE_PACKED_ATTRIBUTE
} __attribute__((packed)) Mystruct;
#else
}Mystruct;
#endif

int main()
{
    // Declare a variable of the structure
    Mystruct obj;

    // Initalize the structure fields
    obj.id = 123;
    snprintf(obj.name, sizeof(obj.name), "Test object");

#ifdef INCLUDE_EXTRA_FIELD
    obj.extra_data = 3.14f;
#endif

    printf("ID: %d\n", obj.id);
    printf("Name: %s\n", obj.name);

#ifdef INCLUDE_EXTRA_FIELD
    printf("Extra data: %.2f\n", obj.extra_data);
#endif

    printf("Size of MyStruct: %zu bytes\n", sizeof(Mystruct));
}
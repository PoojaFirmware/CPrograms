// Program for structure can be defined, initialized, and accessed
#include <stdio.h>
#include <string.h>

struct Person
{
    char name[50];
    int age;
    float height;
};

int main()
{
    // Array of integers
    int number[3] = {10, 20, 30};

    printf("Array of number:%d\n", number[0]);

    // Define and initialize a person structure variable 
    // struct Person person1 = {"Nick", 30, 5.4}; // 1 way  to assign the values

    // Creating a structure variable
    struct Person person1;

    // Assign values to members for 2 way
    person1.age = 25;
    person1.height = 5.4;

    // For Name
    // error: assignment to expression with array type
    // person1.name = "Nick"; 
    // person1.name = "Nick"; 
    // 2 way
    strcpy(person1.name, "Nick"); // Use strcpy to copy the string

    // Accessing and prints the members of structures
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.1f\n", person1.height);

    return 0;
}

// Define a structure with a pointer as a member and demonstrate its use.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pointerstr
{
    char *name; // Pointer to a dynamically allocated string
    int age;
};

int main()
{
    struct pointerstr person;

    person.name = (char *)malloc(50 * sizeof(char));
    if (person.name == NULL)
    {
        printf("Memory allocation\n");
        return 1;
    }

    strcpy(person.name, "Pooja");
    printf("Name:%s\n", person.name);

    person.age = 25;
    printf("Age:%d\n", person.age);

    // Free the allocated memory
    free(person.name);

    return 0;
}
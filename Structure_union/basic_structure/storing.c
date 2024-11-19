// Define a structure and union for 
// storing data in different formats (e.g., int, float, char) and demonstrate how they store memory differently.
// The total size of this structure is affected by alignment and padding.
    // The alignment rule for this structure ensures that the size is a multiple of the largest alignment requirement, which is 4 bytes.
    // Therefore, after charval (1 byte), 3 padding bytes are added to align the total size to 12 bytes.
    // Memory layout is as follows:
    /*
    |  intval  | floatval | charval | padding | padding | padding |
    |  4 bytes |  4 bytes |  1 byte |  1 byte |  1 byte |  1 byte |
    |___________|__________|_________|_________|_________|_________|
    Total Size: 12 bytes
    */

#include <stdio.h>

struct datastruct
{
    int intval;
    float floatval;
    char charval;
};

union dataunion
{
    int intval;
    float floatval;
    char charval;
};

int main()
{
    struct datastruct Datast;
    union dataunion  Dataun;
    
    // Assigning the values for structure
    Datast.intval = 10;
    Datast.floatval = 15.45;
    Datast.charval = 'A';

    // Assigning the values for union
    Dataun.intval = 20;
    Dataun.floatval = 17.45;
    Dataun.charval = 'B'; 

    // Printing the values for the structures
    printf("Structure:\n");
    printf("Size of struct: %lu bytes\n", sizeof(Datast));
    printf("intVal: %d, floatVal: %.2f, charVal: %c\n", Datast.intval, Datast.floatval, Datast.charval);

    // Printing the values for the union
    printf("Union:\n");
    printf("Size of union: %lu bytes\n", sizeof(Dataun));
    printf("intVal: %d, floatVal: %.2f, charVal: %c\n", Dataun.intval, Dataun.floatval, Dataun.charval);
    
}


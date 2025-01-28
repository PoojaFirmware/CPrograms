// Create a union with `packed` and `aligned` attributes and write a program to demonstrate its use in accessing raw memory.
// **Objective**: Show how combined attributes like `packed` and `aligned` can be used to access raw memory efficiently in low-level systems programming.

#include <stdio.h>
#include <stdint.h>

typedef union __attribute__((packed, aliged(4))) 
{
    struct 
    {    
        uint16_t field1;
        uint16_t field2;
        uint8_t field3;
        uint8_t field4;
    };
    uint8_t raw[8];
}PackedAlignedUnion;

int main()
{
    // Create an instance of the union and initialize it
    PackedAlignedUnion data = {
        .field1 = 0x1234,
        .field2 = 0x5678,
        .field3 = 0x9A,
        .field4 = 0xBC
    };

    // Print the fields of the structure
    printf("Field1: 0x%04X\n", data.field1);
    printf("Field2: 0x%04X\n", data.field2);
    printf("Field3: 0x%02X\n", data.field3);
    printf("Field4: 0x%02X\n", data.field4);

    // Print the raw memory representation
    printf("\nRaw memory (byte by byte):\n");
    for (size_t i = 0; i < sizeof(data.raw); i++) {
        printf("Byte %zu: 0x%02X\n", i, data.raw[i]);
    }

    // Modify the raw memory and observe the changes in fields
    data.raw[0] = 0xFF; // Modify the first byte
    data.raw[1] = 0xEE; // Modify the second byte

    printf("\nAfter modifying raw memory:\n");
    printf("Field1: 0x%04X\n", data.field1);
    printf("Field2: 0x%04X\n", data.field2);
    printf("Field3: 0x%02X\n", data.field3);
    printf("Field4: 0x%02X\n", data.field4);

    return 0;
}
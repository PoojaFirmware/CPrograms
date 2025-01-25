// What are practical use cases of the `packed` attribute with unions? Provide a code example.
// **Objective**: Explore real-world scenarios for using `packed` in unions, such as when dealing with network protocols or hardware communication.

#include <stdio.h>
#include <stdint.h>

// Define a packed union for network protocols header
typedef union __attribute__((packed))
{
    struct 
    {
        uint8_t version; // 1 byte
        uint8_t type;    // 1 byte
        uint16_t length; // 2 byte
    }fields;
    uint8_t raw_data[4];
}NetworkHeader;

int main() 
{
    // Create a network header instance
    NetworkHeader header;

    // Set values using the structured fields
    header.fields.version = 1;  // Protocol version
    header.fields.type = 2;     // Message type
    header.fields.length = 256; // Message length

    // Print the raw byte data
    printf("Raw header data:\n");
    for (int i = 0; i < sizeof(header.raw_data); i++) 
    {
        printf("Byte %d: 0x%02X\n", i, header.raw_data[i]);
    }

    // Print the size of the union
    printf("Size of NetworkHeader: %zu bytes\n", sizeof(NetworkHeader));

    return 0;
}
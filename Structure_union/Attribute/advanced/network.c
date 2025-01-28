// ### 3. How can attributes like `packed` and `aligned` be used to implement efficient data structures for protocol parsers? Provide an example.
// **Objective**: Use attributes to create efficient data structures for parsing network protocols.

#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct  __attribute__((packed)) ProtocolHeader
{
    uint8_t version; 
    uint8_t header_length; 
    uint16_t message_type; 
    uint16_t message_length; 
    uint32_t checksum; 
};

void parse_protocol_header(const uint8_t *buffer, struct ProtocolHeader *header)
{
    // Copy raw data into the structure
    memcpy(header, buffer, sizeof(struct ProtocolHeader));
}

void display_protocol_header(const struct ProtocolHeader *header)
{
    printf("Protocol header:\n");
    printf("Version: %u\n", header->version);
    printf("Header Length: %u bytes\n", header->header_length);
    printf("Message Type: 0x%04X\n", header->message_type);
    printf("Message Length: %u bytes\n", header->message_length);
    printf("Checksum: 0x%08X\n", header->checksum);
}

int main()
{
    uint8_t raw_data[] =
    {
        0x01,
        0x10,
        0x00, 0x02,
        0x00, 0x00, 0x01, 0x2C,
        0x12, 0x34, 0x56, 0x78
    };

    struct ProtocolHeader header;

    parse_protocol_header(raw_data, &header);

    display_protocol_header(&header);
        
}
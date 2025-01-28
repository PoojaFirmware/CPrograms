// Write a program to create a network packet structure using a combination of `packed` attribute and unions to ensure memory efficiency.
// **Objective**: Use `packed` and unions to define a memory-efficient structure for network packets.

#include <stdio.h>
#include <stdint.h>

// Define a packed structure for the network packet
struct  __attribute__((packed)) networkPacket
{
    uint16_t header; // 2bytes: packets header
    uint8_t protocol; // 1 bytes: protocol type (TCP, UDP, ICMP)
    uint8_t flags; // 1 bytes: packet flags
    uint16_t checksum; // 2 bytes: checksum for error detection
    union 
    {
        struct 
        {
            uint32_t source_ip; // 4 bytes: sources IP Address
            uint32_t dest_ip; // 4 bytes: destination IP Address
        }ipv4;
        struct 
        {
            uint8_t source_mac[6]; // 6 bytes: source MAC Address
            uint8_t dest_mac[6]; // 6 bytes: destination MAC Address
        }ethernet; // ethernet specific fields
    }payload; // 12 bytes: shared memory for IPV4 or ethernet
    uint8_t data[16]; // 16 bytes: payload data
};

int main()
{
    printf("Size of NetworkPacket structure: %zu bytes\n", sizeof(struct networkPacket));

    // create and initailize packet
    struct networkPacket packet =
    {
        .header = 0x1234,
        .protocol = 0x06,
        .flags = 0x01,
        .checksum = 0xFFFF,
        .payload.ipv4 = {
            .source_ip = 0xC0A80001,
            .dest_ip = 0xC0A80002
        },
        .data = "Hello, network!"
    };

    printf("\nNetwork Packet Details:\n");
    printf("  Header: 0x%X\n", packet.header);
    printf("  Protocol: 0x%X\n", packet.protocol);
    printf("  Flags: 0x%X\n", packet.flags);
    printf("  Checksum: 0x%X\n", packet.checksum);
    printf("  Source IP (IPv4): %u.%u.%u.%u\n",
           (packet.payload.ipv4.source_ip & 0xFF),
           (packet.payload.ipv4.source_ip >> 8) & 0xFF,
           (packet.payload.ipv4.source_ip >> 16) & 0xFF,
           (packet.payload.ipv4.source_ip >> 24) & 0xFF);
    printf("  Destination IP (IPv4): %u.%u.%u.%u\n",
           (packet.payload.ipv4.dest_ip & 0xFF),
           (packet.payload.ipv4.dest_ip >> 8) & 0xFF,
           (packet.payload.ipv4.dest_ip >> 16) & 0xFF,
           (packet.payload.ipv4.dest_ip >> 24) & 0xFF);
    printf("  Payload Data: %s\n", packet.data);

    return 0;
    

}

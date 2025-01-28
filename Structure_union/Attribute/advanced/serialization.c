// Write a program to serialize and deserialize a structure that uses the `packed` attribute for communication over a network.
// **Objective**: Implement serialization and deserialization with `packed` attributes for efficient network communication.

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Define a packed structure for a network packet
struct __attribute__((packed)) NetworkPacket
{
    uint16_t packet_id;
    uint8_t flags;
    uint32_t payload_size;
    uint8_t payload[8];
};

void serialize(const struct NetworkPacket *packet, uint8_t *buffer)
{
    memcpy(buffer, packet, sizeof(struct NetworkPacket));
}

void deserialize(const uint8_t *buffer, struct NetworkPacket *packet)
{
    memcpy(packet, buffer, sizeof(struct NetworkPacket));
}

int main()
{
    // Create and Initialize a structure instance 
    struct NetworkPacket packet = 
    {
        .packet_id = 0xABCD,
        .flags = 0x01,
        .payload_size = 6,
        .payload = "HELLO!"
    };

    // Buffer to hold the serialize data
    uint8_t buffer[sizeof(struct NetworkPacket)];

    serialize(&packet, buffer);

    // Simulate sending serialized data over the network
    printf("Serialized Data (Hexadecimal): ");
    for (size_t i = 0; i < sizeof(buffer); i++) 
    {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    // Deserialize the received byte stream back into a structure
    struct NetworkPacket received_packet;
    deserialize(buffer, &received_packet);

    // Print the deserialized data to verify correctness
    printf("Deserialized Packet:\n");
    printf("Packet ID: 0x%04X\n", received_packet.packet_id);
    printf("Flags: 0x%02X\n", received_packet.flags);
    printf("Payload Size: %u\n", received_packet.payload_size);
    printf("Payload: %s\n", received_packet.payload);

    return 0;
}
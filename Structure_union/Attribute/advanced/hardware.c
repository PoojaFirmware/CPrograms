// Design a structure for a hardware register map that requires precise byte alignment and no padding using attributes.
// - **Objective**: Design structures for hardware interfaces where memory layout is critical, and padding must be avoided.

#include <stdio.h>
#include <stdint.h>

// define a packed structure for a hardware register map 
struct __attribute__((packed)) hardwareRegisterMap
{
    uint32_t control; // 4 bytes
    uint16_t status; // 2 bytes
    uint8_t config; // 1 byte
    uint8_t reserved; // 2 bytes
    uint32_t data; // 4 bytes
};

int main()
{
    struct hardwareRegisterMap reg_map;
    printf("Size of hardware register map: %zu bytes\n", sizeof(reg_map));

    // Initialize the structure (simulate writing to hardware registers)
    reg_map.control = 0x12345678;
    reg_map.status = 0xABCD;
    reg_map.config = 0x42;
    reg_map.reserved = 0x00;  // Reserved field should be zeroed
    reg_map.data = 0xDEADBEEF;

    // Print the register values (simulate reading from hardware registers)
    printf("Control Register: 0x%08X\n", reg_map.control);
    printf("Status Register: 0x%04X\n", reg_map.status);
    printf("Config Register: 0x%02X\n", reg_map.config);
    printf("Reserved: 0x%02X\n", reg_map.reserved);
    printf("Data Register: 0x%08X\n", reg_map.data);

    return 0;
}
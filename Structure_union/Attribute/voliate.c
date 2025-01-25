#include <stdio.h>
#include <stdint.h>

// Simulate a hardware register in memory
typedef struct {
    volatile uint32_t CONTROL;  // Volatile: prevents compiler optimizations
    volatile uint32_t STATUS;   // Volatile: prevents compiler optimizations
    uint32_t DATA;              // Non-volatile
} HardwareReg;

int main() {
    // Simulate memory-mapped hardware registers
    HardwareReg reg = {0};  // Initialize all fields to 0 for simulation

    // Write to the CONTROL register
    reg.CONTROL = 0x1;

    // Print the STATUS register value
    printf("STATUS before hardware update: 0x%X\n", reg.STATUS);

    // Simulate reading CONTROL register repeatedly
    for (int i = 0; i < 5; i++) {
        printf("Reading CONTROL register: 0x%x\n", reg.CONTROL);
    }

    // Write to the DATA register
    reg.DATA = 0xABCD1234;
    printf("DATA register: 0x%X\n", reg.DATA);

    return 0;
}

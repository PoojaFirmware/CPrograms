/*
Program for
1. Packing and unpacking Two 16-bit Integers into a 32-bit Integer
*/

#include <stdio.h>
#include <stdint.h>

uint32_t pack_16bit_to_32bit(uint16_t a, uint16_t b)
{
    
    return ((uint16_t) a << 16) | b;
}

void unpack_rgb(uint32_t packed, uint16_t *a, uint16_t *b)
{
    *a = (packed >> 16) & 0xFFFF;   // Extract the first 8 bits (Red)
    *b = packed & 0xFFFF; // Extract the next 8 bits (Green)
}

int main()
{
    uint16_t a = 0x1234;  
    uint16_t b = 0xABCD;  

    // Packed byte
    uint32_t packed_bytes = pack_16bit_to_32bit(a, b);

    // Unpack the values 
    unpack_rgb(packed_bytes, &a, &b);

    printf("Packed 32-bit: 0x%X\n", packed_bytes);
    printf("Unpacked 16-bit A: 0x%X, B: 0x%X\n", a, b);
    return 0;
}


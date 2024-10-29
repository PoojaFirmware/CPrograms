/*
Program for
Packing and Unpacking 16-bit Values into a 64-bit Integer
*/

#include <stdio.h>
#include <stdint.h>

uint64_t pack_16bit_to_64bit(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
{
    uint64_t packed = 0;
    packed |= (uint64_t)a << 48; //Shift a to highest 16 bits
    packed |= (uint64_t)b << 32; //Shift b to next 16 bits
    packed |= (uint64_t)c << 16; //Shift c to next 16 bits
    packed |= (uint64_t)d; //Shift d to lowest 16 bits
    
    return packed;
}


void unpack(uint64_t packed, uint16_t *a, uint16_t *b, uint16_t *c, uint16_t *d)
{
    *a = (packed >> 48) & 0xFFFF; // Extract the highest 16 bits 
    *b = (packed >> 32) & 0xFFFF; // Extract the next 16 bits 
    *c = (packed >> 16) & 0xFFFF; // Extract the next 16 bits 
    *d = packed & 0xFFFF; // Extract the lowest 8 bits 
}

int main()
{
    uint16_t a = 0x1234;  
    uint16_t b = 0xABCD;
    uint16_t c = 0x5678;  
    uint16_t d = 0x9ABC; 

    // Packed byte
    uint64_t packed_bytes = pack_16bit_to_64bit(a, b, c, d);

    // Unpack the values 
    unpack(packed_bytes, &a, &b, &c, &d);

    printf("Packed 64-bit: 0x%lX\n", packed_bytes);
    printf("Unpacked values: 0x%04X, 0x%04X, 0x%04X, 0x%04X\n", a, b, c, d);
    return 0;
}

/*
Program for
Packing and Unpacking Multiple 8-bit Characters into a 32-bit Integer
*/

#include <stdio.h>
#include <stdint.h>

int pack_chars(unsigned char a, unsigned char b, unsigned char c, uint16_t d)
{
    // Pack the 4 characters into a 32-bit integer
    return (a << 24) | (b << 16) | (c << 8) | d;
}


void unpack(int packed_bytes, unsigned char *a, unsigned char *b, unsigned char *c, unsigned char *d)
{
    // Unpack the characters from the 32-bit integer
    *a = (packed_bytes >> 24) & 0xFF; // Extract the most significant byte
    *b = (packed_bytes >> 16) & 0xFF;
    *c = (packed_bytes >> 8) & 0xFF;
    *d = packed_bytes & 0xFF; // Extract the Least significant byte
}

int main()
{
    unsigned char a = 'A'; // 0x41
    unsigned char b = 'B'; // 0x42
    unsigned char c = 'C'; // 0x43
    unsigned char d = 'D'; // 0x44

    // Packed byte
    int packed_bytes = pack_chars(a, b, c, d);

    // Unpack the values 
    unpack(packed_bytes, &a, &b, &c, &d);

    printf("Packed 32-bit: 0x%X\n", packed_bytes);
    printf("Unpacked values: 0x%04X, 0x%04X, 0x%04X, 0x%04X\n", a, b, c, d);
    return 0;
}

/*
Program for
1. Packing four 2-bit Integers into a Single Byte
2. Unpacking four 2-bit Integers from a Single Byte
*/

#include <stdio.h>
unsigned char pack_into_byte(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    // Ensure all values are within 2 bits range(0 to 3)
    a &= 0x03;
    b &= 0x03;
    c &= 0x03;
    d &= 0x03;
    //Pack them into Single byte
    return (a << 6) | (b << 4) | (c << 2) | d;  
}

void unpacked(unsigned char packed_bytes, unsigned char *a, unsigned char *b, unsigned char *c, unsigned char *d)
{
    // Extract the lower 2 bits using bitwise AND and shift
    *a = (packed_bytes >> 6) & 0x03;
    *b = (packed_bytes >> 4) & 0x03;
    *c = (packed_bytes >> 2) & 0x03;
    *d = packed_bytes & 0x03;
}

int main()
{
    unsigned char a = 2;
    unsigned char b = 3;
    unsigned char c = 1;
    unsigned char d = 0;

    unsigned char packed_bytes = pack_into_byte(a, b, c, d);
    unpacked(packed_bytes, &a, &b, &c, &d);

    printf("Packed byte: %d\n", packed_bytes);
    printf("Unpacked byte: a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}
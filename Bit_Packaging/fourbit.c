/*
Program for
1. Packing Two 4-bit Integers into a Single Byte
2. Unpacking Two 4-bit Integers from a Single Byte
*/

#include <stdio.h>
int pack_into_byte(int x, int y)
{
    // Pack 2 4 bits integers into a byte
    return (y << 4) | (x & 0x0F);  // Mask x to ensure its only 4 bits
}

void unpacked(int packed_bytes, int *x, int *y)
{
    *x = packed_bytes & 0x0F; // Extract the lower 4 bits
    *y = (packed_bytes >> 4) & 0x0F; // Extract the upper 4 bits
}

int main()
{
    int x = 9; // lower 4 bit integers
    int y = 6; // upper 4 bit integers
    int packed_bytes = pack_into_byte(x, y);
    unpacked(packed_bytes, &x, &y);

    printf("Packed byte: %d\n", packed_bytes);
    printf("Unpacked byte: x = %d, y = %d\n", x, y);
    return 0;
}

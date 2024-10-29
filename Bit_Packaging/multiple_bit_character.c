// Packing and Unpacking Multiple 8-bit Characters into a 32-bit Integer

#include <stdio.h>
int pack_into_byte(int x, int y)
{
    // Pack for 4 
    return (y << 4) | (x & 0x0F);  
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
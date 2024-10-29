/*
Program for Packing 5-bit, 6-bit, and 5-bit Values into a 16-bit Integer
*/

#include <stdio.h>

int pack(int a, int b, int c)
{
    a &= 0x1F; // 5 bit(0x1F is 00011111)
    b &= 0x3F; // 6 bit(0x1F is 00111111)
    c &= 0x1F; // 5 bit(0x1F is 00011111)

    int pack_values = a | (b << 5) | (c << 11);
    return pack_values;
}

int main()
{
    int a = 15;
    int b = 45;
    int c = 20;

    int packed = pack(a, b, c);
    printf("Packed 16-bit integer: 0x%04X\n", packed); 
}
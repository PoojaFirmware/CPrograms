/*
Packing a Boolean Value and an Integer into a Single Byte
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t packboolean(bool flag, uint8_t num)
{
    // Ensure the Integer fits in 7 bits
    num &= 0x7F; // It is 01111111 in binary (7 bits set to 1)

    // Shift the boolean flag to the 7 bit
    return (flag << 7) | num;
}

void unpack(uint8_t byte, bool *flag, uint8_t *num)
{
    *flag = (byte >> 7) & 1;
    *num = byte & 0x07;
}

int main()
{
    bool flag = true;
    uint8_t num = 45;
    bool unpack_flag;
    uint8_t unpack_num;

    // Packed byte
    uint8_t packed_bytes = packboolean(flag, num);

    // Unpack the values 
    unpack(packed_bytes, &unpack_flag, &unpack_num);

    printf("Packed 32-bit: 0x%02X\n", packed_bytes);
    printf("Unpacked values: flag = %d, num = %d\n", unpack_flag, unpack_num);
    return 0;
}
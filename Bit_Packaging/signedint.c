/*
Packing a Signed Integer and an Unsigned Integer into a Single 32-bit Integer
*/

#include <stdio.h>
#include <stdint.h>

uint32_t packint16(int16_t signed_part, uint16_t unsigned_part)
{
    // Shift the signed integer to the higher 16 bits and the unsigned integer to the lower 16 bits
    return ((uint32_t)signed_part << 16) | ((uint32_t)unsigned_part);
}

void unpack_values(int32_t packed_value, int16_t *signed_part, int16_t *unsigned_part)
{
    *signed_part = (int16_t)(packed_value >> 16);
    *unsigned_part =(uint16_t)(packed_value);
}

int main()
{
    int16_t signed_part = -12345;
    uint16_t unsigned_part = 54321;

    // Pack the two integers into a single 32 bit integer
    uint32_t packed_value = packint16(signed_part, unsigned_part);
    printf("Packed Value: %d\n", packed_value);

    int16_t unpacked_signed;
    uint16_t unpacked_unsigned;
    unpack_values(packed_value, &unpacked_signed, &unpacked_unsigned);

    printf("Unpacked Signed Part: %d\n", unpacked_signed);
    printf("Unpacked Unsigned Part: %u\n", unpacked_unsigned);
}

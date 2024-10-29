/*
Program for
Packing & unpacking Three 10-bit Values into a 32-bit Integer
*/

#include <stdio.h>
#include <stdint.h>
uint32_t pack_into_word(uint32_t A, uint32_t B, uint32_t C)
{
    // Pack three 10-bit values into a 32-bit integer
    return (A & 0x3FF) | ((B & 0x3FF) << 10) | ((C & 0x3FF) << 20);
}

void unpacked(uint32_t packed, uint32_t *A, uint32_t *B, uint32_t *C)
{
    *A = packed & 0x3FF;        // Extract the first 10 bits (A)
    *B = (packed >> 10) & 0x3FF; // Extract the next 10 bits (B)
    *C = (packed >> 20) & 0x3FF; // Extract the next 10 bits (C)
}

int main()
{
    uint32_t A = 512;
    uint32_t B = 256;
    uint32_t C = 128;

    uint32_t packed_bytes = pack_into_word(A, B, C);
    unpacked(packed_bytes, &A, &B, &C);

    printf("Packed byte: %u\n", packed_bytes);
    printf("Unpacked byte: a = %u, b = %u, c = %u\n", A, B, C);
    return 0;
}
/*
Program for
1. Packing Multiple Fields (RGB values) into a 32-bit Integer
2. Unpacking RGB Values from a 32-bit Packed Integer
*/

#include <stdio.h>
#include <stdint.h>

uint32_t pack_rgb(uint32_t red, uint32_t green, uint32_t blue)
{
    // Pack the RGB values and ensure alpha (transparency) is set to opaque (0xFF)
    return (red << 24) | (green << 16) | (blue << 8) | 0xFF;
}


void unpack_rgb(uint32_t packed, uint32_t *red, uint32_t *green, uint32_t *blue)
{
    *red = (packed >> 24) & 0xFF;   // Extract the first 8 bits (Red)
    *green = (packed >> 16) & 0xFF; // Extract the next 8 bits (Green)
    *blue = (packed >> 8) & 0xFF;   // Extract the next 8 bits (Blue)
}

int main()
{
    uint32_t red = 255;   // Full intensity Red
    uint32_t green = 165; // Medium intensity Green
    uint32_t blue = 0;    // No Blue

    // Pack the RGB values into a 32-bit integer
    uint32_t packed_bytes = pack_rgb(red, green, blue);

    // Unpack the values to verify correctness
    unpack_rgb(packed_bytes, &red, &green, &blue);

    printf("Packed value: 0x%08X\n", packed_bytes);   // Packed RGB value
    printf("Unpacked values: R = %u, G = %u, B = %u\n", red, green, blue); // Unpacked RGB values

    return 0;
}

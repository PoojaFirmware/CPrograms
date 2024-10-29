/*
Program for Packing and Unpacking Floating-Point and Integer Values using memcpy
*/

#include <stdio.h>
#include <string.h>

//Function to pack float into an Integer
int pack_float(float value)
{
    int result;
    memcpy(&result, &value, sizeof(result));
    return result;
}

//Function to unpack integer into an float
float unpack_int(int value)
{
    float result;
    memcpy(&result, &value, sizeof(result));
    return result;
}

int main()
{
    float original_float = 3.14;
    int packed_int = pack_float(original_float);
    float unpacked_float = unpack_int(packed_int);

    printf("Original float: %f\n", original_float);
    printf("Packed as Integer: %d\n", packed_int);
    printf("Unpacked back to Float: %f\n", unpacked_float);

}

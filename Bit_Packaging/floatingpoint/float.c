/*
Program for Packing and Unpacking Floating-Point and Integer Values using pointers
*/

#include <stdio.h>

//Function to pack float into an Integer
int pack_float(float value)
{
    int result;
    // Point an integer pointer to the address of the float
    int *int_ptr = (int *)&value;
    result = *int_ptr;
    return result;
}

//Function to unpack integer into an float
float unpack_int(int value)
{
    float result;
    // Point an float pointer to the address of the integer
    float *float_ptr = (float *)&value;
    result = *float_ptr;
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

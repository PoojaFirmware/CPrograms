/*
Program for Packing and Unpacking Floating-Point and Integer Values using union
*/

#include <stdio.h>

typedef union 
{
    float float_val;
    int int_val;
}FloatIntUnion;

//Function to pack float into an Integer
int pack_float(float value)
{
    FloatIntUnion data;
    data.float_val = value;
    return data.int_val;
}

//Function to unpack integer into an float
float unpack_int(int value)
{
    FloatIntUnion data;
    data.int_val = value;
    return data.float_val;
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

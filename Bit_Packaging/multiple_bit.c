#include <stdio.h>

int set_bits(int num, int bitmask)
{
    return num | bitmask;
}

int main()
{
    int num = 0;
    int bitmask = 0b1010;
    int result = set_bits(num, bitmask);
    printf("Result after setting bits with bitmask %d: %d\n", bitmask, result);
}

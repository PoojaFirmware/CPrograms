//Find the most significant byte (MSB) of a number using bitwise operations

#include <stdio.h>

unsigned char msb(unsigned int num)
{
    // shift the number until the most significant byte is in the lsb
    return (num >> 24) & 0xFF;
}

int main()
{
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    unsigned char result = msb(num);

    printf("The most significant byte (MSB) is: 0x%X\n", msb);

    return 0;
}
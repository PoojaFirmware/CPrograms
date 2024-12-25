// Write a program for packing and unpacking 4 characters in a 32 integers

#include <stdio.h>

// Function to pack 4 characters into a 32 bit integer
unsigned int packCharacters(char c1, char c2, char c3, char c4)
{
    unsigned int packed = 0;
    packed |= (unsigned int)c1 << 24;
    packed |= (unsigned int)c2 << 16;
    packed |= (unsigned int)c3 << 8;
    packed |= (unsigned int)c4;

    return packed;
}

// Function to unpack a 32 bit integer 4 characters
void unpackcharacters(unsigned int packed, char *c1, char *c2, char *c3, char *c4) 
{
    *c1 = (packed >> 24)& 0xFF;
    *c2 = (packed >> 16)& 0xFF;
    *c3 = (packed >> 8)& 0xFF;
    *c4 = packed & 0xFF;
}

int main()
{
    char c1 = 'A', c2 = 'B', c3 ='C', c4 ='D';
    printf("Original characters: %c %c %c %c\n", c1, c2, c3, c4);

    // Packed the characters
    unsigned int packed = packCharacters(c1, c2, c3, c4);
    printf("Packed integer: 0x%x\n", packed);

    //Unpacked the characters
    char uc1, uc2, uc3, uc4;
    unpackcharacters(packed, &uc1, &uc2, &uc3, &uc4);
    printf("unpacked characters: %c %c %c %c\n", packed, uc1, uc2, uc3, uc4);

    return 0;
}

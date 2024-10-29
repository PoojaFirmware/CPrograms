#include <stdio.h>
int main()
{
    unsigned int packedint = 0x12345678;

    // Define mask for each field;
    unsigned int maskField1 = 0xFF;
    unsigned int maskField2 = 0xFF << 8;
    unsigned int maskField3 = 0xFF << 16;

    // Extract each field
    unsigned int field1 = (packedint & maskField1);
    unsigned int field2 = (packedint & maskField2);
    unsigned int field3 = (packedint & maskField3);

    printf("Field1: 0x%0X\n", field1);
    printf("Field2: 0x%0X\n", field2);
    printf("Field3: 0x%0X\n", field3);
}
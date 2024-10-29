/*
Shifting and Masking for Bit-Field Extraction
*/

#include <stdio.h>
int extract_bit(unsigned int data, int start, int num)
{
    unsigned int shifted = data >> start;
    unsigned int mask = (1 << num) - 1;
    return shifted & mask;
}

// Function to print binary with leading zeros for a specified bit width
void print_binary(int value, int bit_width) {
    for (int i = bit_width - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

int main()
{
    unsigned int data = 0b11011010;
    int start = 4;
    int num = 3;
    int extracted = extract_bit(data, start, num);

    printf("Original data: 0b11011010\n");
    printf("Extracted bits: 0b");
    print_binary(extracted, num);  // Print with leading zeros for 3 bits
    printf(" (decimal %d)\n", extracted);
}
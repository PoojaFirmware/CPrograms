#include <stdio.h>

unsigned int pack_Date(int day, int month, int year) 
{
    // 12 bits for year, 4 bits for month, 5 bits for day
    unsigned int packed = (year << 9) | (month << 5) | day;
    //printf("Packing - Year: %d, Month: %d, Day: %d => Packed: %u\n", year, month, day, packed);
    return packed;
}

void unpack(unsigned int packed, int *day, int *month, int *year) 
{
    *year = (packed >> 9) & 0xFFF;   // 12 bits for year
    *month = (packed >> 5) & 0xF;    // 4 bits for month
    *day = packed & 0x1F;            // 5 bits for day
    //printf("Unpacking - Packed: %u => Year: %d, Month: %d, Day: %d\n", packed, *year, *month, *day);
}

int main() {
    int year = 1999;
    int month = 2;
    int day = 13;

    // Pack the date
    unsigned int result_packed = pack_Date(day, month, year);
    printf("The packed date is %u\n", result_packed);

    // Unpack the date
    unpack(result_packed, &day, &month, &year);
    printf("The unpacked date is: Year = %d, Month = %d, Day = %d\n", year, month, day);

    return 0;
}

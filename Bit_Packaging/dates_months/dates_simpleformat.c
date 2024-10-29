#include <stdio.h>

int packDate1(int day, int month, int year) 
{
    return (year * 10000) + (month * 100) + day;
}

void unpackDate1(int packedDate, int *day, int *month, int *year) 
{
    *year = packedDate / 10000;
    *month = (packedDate % 10000) / 100;
    *day = packedDate % 100;
}

int main() {
    int year = 1999;
    int month = 2;
    int day = 13;

    // Pack the date
    int result_packed = packDate1(day, month, year);
    printf("The packed date is %u\n", result_packed);

    // Unpack the date
    unpackDate1(result_packed, &day, &month, &year);
    printf("The unpacked date is: Year = %d, Month = %d, Day = %d\n", year, month, day);

    return 0;
}

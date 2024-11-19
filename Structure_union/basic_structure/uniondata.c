//  Program: Write a program to initialize a union with different data types and observe which member holds the data.
// A union allows storing different data types in the same memory location.
// Only one member can hold a valid value at a time. Assigning a new value
// to one member will overwrite the previous value, leading to unpredictable
// (garbage) values if you read from a different member.

#include <stdio.h>
#include <string.h>

union uniondata
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union uniondata data;
    data.i = 20;
    printf(" The integer value is:%d\n", data.i);

    // Assign float value to the union
    // This will overwrite the integer value
    data.f = 13.2;
    printf(" The float value is:%.1f\n", data.f);
    printf(" Now leftover int value is:%d\n", data.i);

    strcpy(data.str, "program");
    printf(" The character value is:%s\n", data.str);
    printf(" Now leftover int value is:%d\n", data.i);
    printf(" Now leftover float value is:%.1f\n", data.f);
}

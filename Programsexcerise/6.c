// Write a program to Convert a temperature in celsius into fahrenheit

#include <stdio.h>
#define CONVERSION_FACTOR (9.0/5.0)
int main()
{
    int celsius; 
    float fahrenheit;
    printf("Enter the celsius: ");
    scanf("%d", &celsius);

    fahrenheit = (celsius + CONVERSION_FACTOR) + 32;

    printf("fahrenheit is: %f\n", fahrenheit);
}
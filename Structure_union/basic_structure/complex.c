// Create a structure to store a complex number and write a program to add two complex numbers.

#include <stdio.h>

struct complex
{
    float real;
    float img;
};

void complexadd(struct complex *result, struct complex c1, struct complex c2)
{
    result->real = c1.real + c2.real;
    result->img = c1.img + c2.img;
}

int main()
{
    struct complex num1 = {3.4, 5.6};
    struct complex num2 = {3.5, 5.8};
    struct complex result;

    complexadd(&result, num1, num2);

    printf("Sum of complex numbers: %.1f + %.1fi\n", result.real, result.img); 
}


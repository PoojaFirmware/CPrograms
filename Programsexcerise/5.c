// Write a program for radius of circle of area and Perimeter

#include <stdio.h>
#define pi 3.14
int main()
{
    int r, area, Perimeter;
    printf("Enter the radius: ");
    scanf("%d", &r);

    area = pi * r * r;
    Perimeter = 2 * pi * r;
    
    printf("The area of circle: %d\n", area);
    printf("The Perimeter of circle: %d\n", Perimeter);
}
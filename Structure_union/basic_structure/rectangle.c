// Write a program to define a structure representing a rectangle and calculate its area and perimeter

#include <stdio.h>

struct rectangle
{
    float length;
    float width;
}rect;

float arearectangle(struct rectangle rect)
{
    float area = rect.length * rect.width;
    return area; 
}

float perimeterrectangle(struct rectangle rect)
{
    float perimeter =  2 * rect.length * rect.width;
    return perimeter; 
}

int main()
{
    // Input rectangle dimensions
    printf("Enter the length of the rectangle: ");
    scanf("%f", &rect.length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &rect.width);

    // Calculate area and perimeter
    float area = arearectangle(rect);
    float perimeter = perimeterrectangle(rect);

    // Display the results
    printf("Area of the rectangle: %.2f\n", area);
    printf("Perimeter of the rectangle: %.2f\n", perimeter);
}


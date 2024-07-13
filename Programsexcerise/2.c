// Write a program that aacepts marks in 5 subjects and calculates the total percentage in marks

#include <stdio.h>
int main()
{
    int a, b, c, d, e, total_marks = 0;
    float percentage;
    printf("Enter the 5 subjectmarks: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    total_marks = a + b + c + d;
    percentage = (total_marks / 500.00)* 100;
    printf("The total percentage of subjects: %f\n", percentage);
}
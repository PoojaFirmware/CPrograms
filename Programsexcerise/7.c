// Program to find out the grades of a student when the arks of 4 subjects are given:
//    percentage >= 85                       - grade A
//    percentage < 85 and percentage >= 70   - grade B
//    percentage < 70 and percentage >= 55   - grade C
//    percentage < 55 and percentage >= 40   - grade D
//    percentage < 40                        - grade E

#include<stdio.h>
int main()
{
    float percentage, total;
    float m1, m2, m3, m4;
    printf("Enter marks of 4 subjects: ");
    scanf("%f %f %f %f", &m1, &m2, &m3, &m4);

    total = m1 + m2 + m3 + m4;
    percentage = total/4;

    if(percentage >= 85)
    {
        printf("Grade A\n");
    }
    else if(percentage < 85 && percentage >= 70)
    {
        printf("Grade B\n");
    }
    else if(percentage < 70 && percentage >= 55)
    {
        printf("Grade C\n");
    }
    else if(percentage < 55 && percentage >= 40)
    {
        printf("Grade D\n");
    }
    else if(percentage < 40)
    {
        printf("Grade E\n");
    }

    return 0;
}
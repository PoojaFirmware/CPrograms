// Define a structure to store student information (name, age, grade) and initialize it.

#include <stdio.h>
#include <string.h>

struct studentinfo
{
    char name[50];
    int age;
    char grade;
}student1; // Initalize the structure

int main()
{
    // Assign the values to student information
    student1.age = 25;
    student1.grade = 'A';

    strcpy(student1.name, "Nick");

    printf("student information:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("grade: %c\n", student1.grade);
}



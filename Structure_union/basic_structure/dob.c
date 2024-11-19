/*
    Program: Write a function to pass a structure containing a date of birth and calculate age.
    
    Adjust the calculated age if the current date is before the person's birthday
    in the current year. Here's the logic:
    - If the current month is earlier than the birth month, the birthday hasn't 
      occurred yet this year, so we subtract 1 from the age.
    - If the current month is the same as the birth month but the current day is 
      earlier than the birth day, the birthday also hasn't occurred yet, so we subtract 1.
    
    Why Subtract Age:
    If the current date is before the person’s birthday in the current year, their age would technically be one year 
    less than the simple difference between the current year and their birth year.
    This is why the age is decremented (age--) in this case.

    Example:
    1. Date of Birth: 15 August 1990
       Current Date: 4 November 2024
       - Birthday has passed, so age is 2024 - 1990 = 34.
    
    2. Date of Birth: 15 August 1990
       Current Date: 4 July 2024
       - Birthday hasn't occurred yet, so age is adjusted to 2024 - 1990 - 1 = 33.
*/
#include <stdio.h>

struct DateOfBirth
{
    int year;
    int month;
    int day;
}dob;

int calculateAge(struct DateOfBirth dob, int currentyear, int currentmonth, int currentday)
{
    int age = currentyear - dob.year;

    // Adjust age if the current date is before the birth date
    // Current month is earlier than date of birth month - currentmonth < dob.month
    // Current month is similar date of birth month but current day is earlier than date of birth day
    // currentmonth == dob.month && Currentday < dob.day
    if (currentmonth < dob.month || (currentmonth == dob.month && currentday < dob.day))
    {
        age--;
    }
    return age;
}

int main()
{
    int currentyear, currentmonth, currentday;

    // Enter the date of bith year, month, day
    printf("Enter the date of birth (DD MM YYYY):");
    scanf("%d %d %d", &dob.day, &dob.month, &dob.year);

    // Enter the current year, month, day
    printf("Enter the current date (DD MM YYYY):");
    scanf("%d %d %d", &currentday, &currentmonth, &currentyear);

    int age = calculateAge(dob, currentyear, currentmonth, currentday);
    printf("Age:%d\n", age);

    return 0;
}

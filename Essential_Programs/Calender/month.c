// To print the calender of month

#include <stdio.h>

// To calculate the day of the week for the first day of a given month and year
// using Zeller's Congruence agorithm.
int getFirstDayofMonth(int month, int year)
{
    int day = 1;
    // To adjust the year based on month. If month is jan (i.e 13th and 14th of the previour year)
    // It effectively shifts these months to be treated as part of the previous year.
    // (14 - month) / 12 will be 1 for January (month = 1) and February (month = 2), causing year to be decremented by 1.
    // For other months, (14 - month) / 12 will be 0, and year remains unchanged.
    int y = year - (14 - month) / 12;
    //It is consider for leap year
    int x = y + y / 4 - y / 100 + y / 400;
    // It is to adjust the months  (14 - month) / 12) is 1 for janurary and feburary and subtract 2 for other months
    int m = month + 12 * ((14 - month) / 12) - 2;
    // To calculate day of the week. x is adjust year, (31 * m) / 12) adjust the month value into formula
    // 0: Sat, 1: Sun, 2: Mon, 3:Tue ....etc.
    int d = (day + x + (31 * m) / 12) % 7;
    return d;
}

// To determine its a leap year or not.
int leapyear(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// To get the number of days in a month and prints the month name
int getDaysandPrintMonths(int month, int year)
{
    switch(month)
    {
        case 1: printf("January");
                return 31;
        case 2: printf("February");
                return leapyear(year) ? 29: 28;
        case 3: printf("March");
                return 31;
        case 4: printf("April");
                return 30;
        case 5: printf("May");
                return 31;
        case 6: printf("June");
                return 30;
        case 7: printf("July");
                return 30;
        case 8: printf("August");
                return 31;
        case 9: printf("Sep");
                return 30;
        case 10: printf("Oct");
                return 31;
        case 11: printf("Nov");
                return 30;
        case 12: printf("Dec");
                return 31;
        default: return 0;
    }
}

// To print the calender of a given month and year
void printCalender(int month, int year)
{
    printf(" ");
    int daysInMonth = getDaysandPrintMonths(month, year);
    printf("%d\n", year);
    printf("Sun Mon Tue Wed Thru Fri Sat\n");

    int firstDay = getFirstDayofMonth(month, year);

    for (int i = 0; i < firstDay; i++)
    {
        printf("    "); // Space for actual dates 
    }

    for (int day = 1; day <= daysInMonth; day++)
    {
        printf("%4d", day); //Proper alignment
        if ((day + firstDay) % 7 == 0)
        {
            printf("\n");
        }
    }
    if ((daysInMonth + firstDay) % 7 == 0)
    {
        printf("\n");
    }
}

int main()
{
    int month, year;
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1) {
        printf("Invalid month or year.\n");
        return 1;
    }

    printCalender(month, year);
    return 0;
}
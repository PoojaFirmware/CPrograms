// Program for Decimal to binary, octal, hexadecimal
/* Few notes
Zero Handling: Your handling of zero in each function is correct. It ensures that 0 is properly printed.
Formatting: Ensure that there's a space or appropriate formatting for readability.
Recursion Depth: Although your code handles recursion correctly, for very large numbers, you might 
run into issues with recursion depth depending on your system. For most practical purposes, this won't be an issue.
*/

#include <stdio.h>
void decimaltobinary(int n)
{
    // Handle the case where n is zero separately
    if (n == 0)
    {
        printf("0");
        return;
    }

    if(n > 0)
    {
        decimaltobinary(n / 2); // Recursive call with integer division by 2
    }
    printf("%d", n % 2);
}

void decimaltooctal(int n)
{
    // Handle the case where n is zero separately
    if (n == 0)
    {
        printf("0");
        return;
    }

    if(n >= 8)
    {
        decimaltooctal(n / 8); // Recursive call with integer division by 8
    }
    printf("%d", n % 8);
}

void decimaltohexa(int n)
{
    // Handle the case where n is zero separately
    if (n == 0)
    {
        printf("0");
        return;
    }

    if(n >= 16)
    {
        decimaltohexa(n / 16); // Recursive call with integer division by 16
    }
    int rem = n % 16;
    if (rem < 10)
    {
        printf("%d", rem); //prints the digits 0-9 
    }
    else 
    {
        printf("%c", rem - 10 + 'A'); // prints the digits 10-15 or A or F. 
    }

}


int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d", &n);

    printf("The binary equivalent:");
    decimaltobinary(n);
    printf("\n");

    printf("The octal equivalent:");
    decimaltooctal(n);
    printf("\n");

    printf("The Hexadecimal equivalent:");
    decimaltohexa(n);
    printf("\n");
}
//Program to convert the decimal, binary, octal, hexadecimal using array

#include <stdio.h>
void decimaltobinary(int n)
{
    int binary[32]; //Array to store binary digits integers
    int i = 0;

    // Handle the case where n is zero separately
    if (n == 0)
    {
        printf("0");
        return;
    }

    //Convert a decimal to binary & store in an array
    while (n > 0)
    {
        binary[i] = n % 2; // reminader
        n = n / 2; //divide by 2 and move to next binary;
        i++; 
    }

    //Print the binary number in reverse order
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void decimaltooctal(int n)
{
    int octal[32]; //Array to store octal digits integers
    int i = 0;

    // Handle the case where n is zero separately
    if (n == 0)
    {
        printf("0");
        return;
    }

    //Convert a decimal to binary & store in an array
    while (n > 0)
    {
        octal[i] = n % 8; // reminader
        n = n / 8; //divide by 8 and move to next binary;
        i++; 
    }

    //Print the binary number in reverse order
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decimaltohexa(int n)
{
    int hexa[32]; //Array to store octal digits integers
    int i = 0;

    // Handle the case where n is zero separately
    if (n == 0)
    {
        printf("0");
        return;
    }

    //Convert a decimal to binary & store in an array
    while (n > 0)
    {
        int rem = n % 16; // reminader
        if (rem < 10)
        {
            hexa[i] = rem + '0';
        }
        else
        {
            hexa[i] = rem - 10 + 'A';
        }

        n = n / 16; //divide by 16 and move to next binary;
        i++; 
    }

    //Print the binary number in reverse order
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", hexa[j]);
    }
    printf("\n");
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
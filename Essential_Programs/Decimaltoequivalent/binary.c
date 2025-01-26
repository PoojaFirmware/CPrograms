// Program for binary, octal, hexadecimal to Decimal.

#include <stdio.h>
int binarytodecimal(int n)
{
    int decimal = 0;
    int base = 1;
    int rem;

    while(n > 0)
    {
        rem = n % 10;
        decimal = decimal + rem * base;
        n = n / 10;
        base = base * 2;
    }
    return decimal;
}

int octaltodecimal(int n)
{
    int decimal = 0;
    int base = 1;
    int rem;

    while(n > 0)
    {
        rem = n % 10;
        decimal = decimal + rem * base;
        n = n / 10;
        base = base * 8;
    }
    return decimal;
}

int hexatodecimal(int n)
{
    int decimal = 0;
    int base = 1;
    int value;
    char hexa;

    printf("Enter the hexa decimal which end with a non-hexa character: ");
    hexa = getchar(); // read the 1st character

    // Contiune reading the characters until the encounter with a nonhexa digits characters.
    while((hexa >= '0' && hexa <= '9') || (hexa >= 'A' && hexa <= 'F') || (hexa >= 'a' && hexa <= 'f'))
    {
        if (hexa >= '0' && hexa <= '9')
        {
            value = hexa - '0';
        }
        else if (hexa >= 'A' && hexa <= 'F')
        {
            value = hexa - 'A' + 10;
        }
        else if (hexa >= 'a' && hexa <= 'f')
        {
            value = hexa - 'a' + 10;
        }
        else
        {
            printf("Invalid digits: %c", hexa);
            return -1;
        }
    decimal = decimal * 16 + value;
    hexa = getchar(); //Read the next character
    }
    return decimal;
}

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d", &n);

    int decimaltob = binarytodecimal(n);
    printf("The binary equivalent:%d", decimaltob);
    printf("\n");

    int decimaltoo = octaltodecimal(n);
    printf("The octal equivalent:%d", decimaltoo);
    printf("\n");

    while(getchar() != '\n'); //Flush the input buffer

    int decimaltoh = hexatodecimal(n);
    if (decimaltoh != -1)
    {
        printf("The hexa equivalent:%d", decimaltoh);
    }
    printf("\n");

    return 0;
}

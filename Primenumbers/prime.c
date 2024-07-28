// Prime number using for loop and modulos operator

#include <stdio.h>
#include <stdbool.h>
int isprime(int n)
{
    int i;
    if (n < 0)
    {
        return false;
    }
    for(i = n; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if (isprime(num))
    {
        printf("%d is prime\n");
    }
    else
    {
        printf("%d is not prime\n");
    }
}
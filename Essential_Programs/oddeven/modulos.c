// Even and odd Program using modulos or standard apporach

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if ((n % 2)== 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }
}

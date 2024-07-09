#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    (((n / 2) * 2) == n) ? printf("even\n") : printf("odd\n");
    return 0;
}
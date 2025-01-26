// Even and odd Program Bitwise AND with conditional operator

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    ((n & 1) == 0) ? printf("even\n"): printf("odd\n");
    return 0;
}

// Even and odd Program using conditional operator

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    (n % 2 == 0)? printf("even\n"): printf("odd\n");
    return 0;
}

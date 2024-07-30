//Add 2 numbers using comma operator and function.

#include<stdio.h>
int add(int a, int b)
{
    return (a += 7, b += 3, a+b);
}

int main()
{
    int a = 0; 
    int b = 0;
    int res = add(a, b);
    printf("the result = %d\n", res);
}

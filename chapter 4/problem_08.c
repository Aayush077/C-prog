//WAP to calculate the factorial of a number using  loop.
#include<stdio.h>
int main()
{
    int i = 1, fact = 1, n;
    printf("Enter a number: ");
    scanf("%d", &n);
    do
    {
        fact = fact * i;
        i++;
    }
    while (n >= i);
    printf("The factorial of %d is %d.\n", n, fact);
    return 0;
}
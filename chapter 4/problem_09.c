// repeat the previous problem using a while loop
#include<stdio.h>
int main()
{
    int i = 1, fact = 1, n;
    printf("Enter a number:");
    scanf ("%d", &n);
    while (n >= 1)
    {
        fact = fact * n;
        n--;
    }
    printf ("The factorial of %d is %d.\n",n, fact);
}
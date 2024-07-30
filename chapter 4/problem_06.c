// implement program 05 using do while.
#include <stdio.h>
int main()
{
    int n, i = 1, sum = 0;
    printf("Enter the natural number you want sum upto : ");
    scanf("%d", &n);

    do
    {
        sum = sum + i;
        i++;
    }
    while (n >= i);
    printf("The sum of natural number upto %d.\n", sum);
}
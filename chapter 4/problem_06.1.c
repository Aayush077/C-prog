//// implement program 05 using for loop.
#include<stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter the natural number you want sum upto : ");
    scanf("%d", &n);

    for ( int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("The sum of natural number upto %d.\n", sum);

}

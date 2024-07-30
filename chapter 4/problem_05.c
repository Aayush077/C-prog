//sum of first 10 natural number using while loop
#include<stdio.h>
int main()
{
    int n, i=1, sum=0;
    printf("Enter the natural number you want sum upto : ");
    scanf("%d", &n);
    
    while (n >= i)
    {
        sum = sum + i;
        i++;
    }
    printf("The sum of natural number upto %d.\n", sum);
    
}
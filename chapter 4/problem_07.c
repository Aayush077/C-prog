//WAP to calculate the sum of the number occuring in the multiplication table of 8(consider 8 x 1 to 8 x 10).
#include<stdio.h>

int main()
{
    int i = 1, sum = 0;
    do
    {
        sum = sum + 8 * i;
        i++;
    }
    while (10 >= i);
    printf("The sum of the number occuring in the multiplication table of 8 upto 8 x 10 is %d.\n", sum);
    return 0;

}
// check whether a number is divisible by 97.
#include <stdio.h>
int main()
{
    int a;
    printf("Enter a number you want to divide with 97: \n");
    scanf("%d", &a);
    if (a % 97 == 0)
    {
        printf("The number is divisible by 97. \n");
    }
    else
    {
        printf("The number is not divisible by 97.");
    }
}
//Multiplication table in reverse
#include <stdio.h>
int main()
{
    int n, i, a;
    printf("Enter the number you want for multiplication table: ");
    scanf("%d", &n);
    printf("The multiplication table for %d in reverse is given below.\n", n);
    for (i = 10; i >= 1; i--)
    {
        a = n * i;
        printf("%d x %d = %d.\n", n, i, a);
    }
}
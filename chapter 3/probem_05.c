// WAP to find if the character is lowercase or not

#include <stdio.h>
int main()
{
    char ch;
    printf("Enter the character you want to check: ");
    scanf("%c", &ch);
    printf("The value of the character is: %d.\n", ch);

    if (ch >= 97 && ch <= 122)
    {
        printf("The character is in Lower case.");
    }
    else
    {
        printf("The character is in Upper case.");
    }
    return 0;
}
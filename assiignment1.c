#include <stdio.h>
#include <string.h>

int str_len( char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int str_cmp( char *str1,  char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void str_cpy(char *r,  char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        r[i] = s[i];
        i++;
    }
    r[i] = '\0';
}

void str_cat(char *r,  char *s)
{
    int i = 0, j = 0;
    while (r[i] != '\0')
    {
        i++;
    }
    while (s[j] != '\0')
    {
        r[i] = s[j];
        i++;
        j++;
    }
    r[i] = '\0';
}

void str_rev(char *str)
{
    int s = 0;
    int e = str_len(str) - 1;
    char temp;
    while (s < e)
    {
        temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;
    }
}

int main()
{
    char str1[100], str2[100], result[200];
    char reversed_str1[100];
    char custom_copied[100], custom_concat[200], custom_reversed[100];

    printf("Enter the 1st string: ");
    scanf("%s", str1);

    printf("Enter the 2nd string: ");
    scanf("%s", str2);

    printf("\nUsing predefined functions:\n");
    printf("Length of str1: %d\n", strlen(str1));
    printf("Comparing str1 and str2: %d\n", strcmp(str1, str2));

    strcpy(result, str1);
    printf("Copied string (str1 to result): %s\n", result);

    strcat(result, str2);
    printf("Combining of str1 and str2: %s\n", result);

    str_cpy(reversed_str1, str1);
    str_rev(reversed_str1);
    printf("Reversed str1: %s\n", reversed_str1);

    printf("\nUsing custom functions:\n");
    printf("Length of str1: %d\n", str_len(str1));
    printf("Comparing str1 and str2: %d\n", str_cmp(str1, str2));

    str_cpy(custom_copied, str1);
    printf("Copied string (str1 to custom_copied): %s\n", custom_copied);

    str_cpy(custom_concat, str1);
    str_cat(custom_concat, str2);
    printf("Combining of str1 and str2: %s\n", custom_concat);

    str_cpy(custom_reversed, str1);
    str_rev(custom_reversed);
    printf("Reversed str1: %s\n", custom_reversed);

    return 0;
}

#include <stdio.h>

int main()
{
    int deg1, deg2, max_deg;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);

    int poly1[deg1 + 1];
    printf("\nEnter the coefficients of the first polynomial:\n");
    for (int i = 0; i <= deg1; i++)
    {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &deg2);

    int poly2[deg2 + 1];
    printf("\nEnter the coefficients of the second polynomial:\n");
    for (int i = 0; i <= deg2; i++)
    {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    if (deg1 > deg2)
    {
        max_deg = deg1;
    }
    else
    {
        max_deg = deg2;
    }

    int result[max_deg + 1];

    // Initialize result array to 0
    for (int i = 0; i <= max_deg; i++)
    {
        result[i] = 0;
    }

    // Add coefficients of the first polynomial to the result
    for (int i = 0; i <= deg1; i++)
    {
        result[i] = poly1[i];
    }

    // Add coefficients of the second polynomial to the result
    for (int i = 0; i <= deg2; i++)
    {
        result[i] = result[i] + poly2[i];
    }

    // Print the sum of polynomials
    printf("\nSum of polynomials: ");
    for (int i = max_deg; i >= 0; i--)
    {
        if (result[i] != 0)
        {
            printf("%dx^%d", result[i], i);
            if (i != 0)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");

    return 0;
}

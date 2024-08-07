// WAP to multiply two polynomial
#include <stdio.h>
// multiplication of two polynomial
void polyMul(int arr1[], int arr2[], int *n, int *mul)
{
    mul[i]=0;
    for (int i = 0; i <= *n; i++)
    {
        for (int j = 0; j <= *n; j++)
        {
            mul[i + j] += arr1[i] * arr2[j];
        }
    }
}

int main()
{
    int n;
    int arr1[100], arr2[100], mul[100];
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the element for first poynomial: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the element for second poynomial: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    polyMul(arr1, arr2, mul, n + 1);

    printf("Polynomial is: \n");
    for (int i = 0; i <= 2 * n; i++)
    {
        printf("%d ", mul[i]);
    }
    return 0;
}

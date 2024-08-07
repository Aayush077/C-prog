#include <stdio.h>
#include <stdlib.h>
 void polyadd(int arr1[], int arr2[], int n, int sum[])
    {
        for (int i = 0; i < n; i++)
        {
            sum[i] = arr1[i] + arr2[i];
        }
    }

int main()
{

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int sum[n+1], arr1[n+1], arr2[n+1];

    printf("Enter the elements of first polynomial: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements of second polynomial: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    polyadd(arr1, arr2, sum,n+1);

    printf("Resultant polynomial is:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", sum[i]);
        if (i != 0)
        {
            printf("x^%d ", i);
        }
        if (i != n)
        {
            printf("+ ");
        }
    }
    return 0;
}
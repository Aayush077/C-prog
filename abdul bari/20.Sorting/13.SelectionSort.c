#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    SelectionSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
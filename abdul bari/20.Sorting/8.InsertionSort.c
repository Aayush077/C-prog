#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[], int n)
{
    int i, j, x;
    for (i=1;i<n;i++)
    {
        j = i-1;
        x = A[i];
        while (j>=0 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (int i=0;i<n;i++)
        scanf("%d", &A[i]);
    InsertionSort(A, n);
    printf("Sorted array: ");
    for (int i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int A[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10, i;
    BubbleSort(A, n);
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
/*Write a program to perform the following operations on a given square matrix using functions:
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/
#include <stdio.h>

int NonZero(int mat[][10], int s)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (mat[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

void UpperTriangle(int mat[][10], int s)
{
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (j >= i)
            {
                printf("%d ", mat[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void DiagonalElements(int mat[][10], int s)
{
    printf("Elements just above the main diagonal:\n");
    for (int i = 0; i < s - 1; i++)
    {
        printf("%d ", mat[i][i + 1]);
    }
    printf("\nElements just below the main diagonal:\n");
    for (int i = 1; i < s; i++)
    {
        printf("%d ", mat[i][i - 1]);
    }
    printf("\n");
}

int main()
{
    int s, mat[10][10];

    printf("Enter the size of the square matrix: ");
    scanf("%d", &s);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int count = NonZero(mat, s);
    printf("Number of non-zero elements: %d\n", count);

    UpperTriangle(mat, s);

    DiagonalElements(mat, s);

    return 0;
}

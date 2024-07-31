/*Write a program to perform the following operations on a given square matrix using functions:
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/
#include <stdio.h>

int countNonZero(int matrix[][10], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

void displayUpperTriangular(int matrix[][10], int size)
{
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= i)
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void displayDiagonalElements(int matrix[][10], int size)
{
    printf("Elements just above the main diagonal:\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", matrix[i][i + 1]);
    }
    printf("\nElements just below the main diagonal:\n");
    for (int i = 1; i < size; i++)
    {
        printf("%d ", matrix[i][i - 1]);
    }
    printf("\n");
}

int main()
{
    int size, matrix[10][10];

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int nonZeroCount = countNonZero(matrix, size);
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    displayUpperTriangular(matrix, size);

    displayDiagonalElements(matrix, size);

    return 0;
}

// 2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>

int main()
{
    int rows, cols, i, j, k = 0;
    int sparse_matrix[10][10], size[10][3];

    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of sparse matrix: \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &sparse_matrix[i][j]);
        }
    }

    // Create the 3-tuple representation
    size[k][0] = rows;
    size[k][1] = cols;
    size[k][2] = 0;
    k++;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                size[k][0] = i;
                size[k][1] = j;
                size[k][2] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    // Update the number of non-zero elements in the 3-tuple representation
    size[0][2] = k - 1;

    // Print the 3-tuple representation
    printf("Sparse matrix in 3-tuple format:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d   %d   %d\n", size[i][0], size[i][1], size[i][2]);
    }

    return 0;
}

// 2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>

int main()
{
    int rows, cols, i, j, k = 0;
    int spamat[10][10], s[10][10];

    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of sparse matrix: \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &spamat[i][j]);
        }
    }

    s[k][0] = rows;
    s[k][1] = cols;
    s[k][2] = 0;
    k++;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (spamat[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = spamat[i][j];
                k++;
            }
        }
    }

    s[0][2] = k - 1;
    printf("Sparse matrix in 3-tuple format:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d   %d   %d\n", s[i][0], s[i][1], s[i][2]);
    }

    return 0;
}

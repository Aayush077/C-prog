#include <stdio.h>

void transpose(int transmat[][3], int spamat[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        transmat[i][0] = spamat[i][1];
        transmat[i][1] = spamat[i][0];
        transmat[i][2] = spamat[i][2];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (transmat[i][0] > transmat[j][0] || (transmat[i][0] == transmat[j][0] && transmat[i][1] > transmat[j][1]))
            {

                int temp[3];
                temp[0] = transmat[i][0];
                temp[1] = transmat[i][1];
                temp[2] = transmat[i][2];

                transmat[i][0] = transmat[j][0];
                transmat[i][1] = transmat[j][1];
                transmat[i][2] = transmat[j][2];

                transmat[j][0] = temp[0];
                transmat[j][1] = temp[1];
                transmat[j][2] = temp[2];
            }
        }
    }

    printf("Transposed Sparse Matrix:\nR C Element\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", transmat[i][0], transmat[i][1], transmat[i][2]);
    }
}

int main()
{
    int n;

    printf("Enter the number of non-zero elements in the sparse matrix: ");
    scanf("%d", &n);

    int spamat[n][3];
    int transmat[n][3];

    printf("Enter the sparse matrix in 3-tuple format (row col value):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &spamat[i][0], &spamat[i][1], &spamat[i][2]);
    }

    transpose(transmat, spamat, n);
    return 0;
}
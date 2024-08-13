// 3.2 WAP to perform addition of two given sparse matrix in 3–tuple format.
#include <stdio.h>

    void add_sparse(int spa_mat1[][3], int spa_mat2[][3], int non_zero1, int non_zero2)
    {
        int result[non_zero1 + non_zero2][3];
        int i = 0, j = 0, k = 0;

        // Loop until either matrix is fully traversed
        while (i < non_zero1 && j < non_zero2)
        {
            if (spa_mat1[i][0] < spa_mat2[j][0] || (spa_mat1[i][0] == spa_mat2[j][0] && spa_mat1[i][1] < spa_mat2[j][1]))
            {
                // Add the smaller element from the first matrix
                result[k][0] = spa_mat1[i][0];
                result[k][1] = spa_mat1[i][1];
                result[k][2] = spa_mat1[i][2];
                i++;
            }
            else if (spa_mat2[j][0] < spa_mat1[i][0] || (spa_mat2[j][0] == spa_mat1[i][0] && spa_mat2[j][1] < spa_mat1[i][1]))
            {
                // Add the smaller element from the second matrix
                result[k][0] = spa_mat2[j][0];
                result[k][1] = spa_mat2[j][1];
                result[k][2] = spa_mat2[j][2];
                j++;
            }
            else
            {
                // If both elements are at the same position, add their values
                result[k][0] = spa_mat1[i][0];
                result[k][1] = spa_mat1[i][1];
                result[k][2] = spa_mat1[i][2] + spa_mat2[j][2];
                i++;
                j++;
            }
            k++;
        }

        // Add remaining elements of the first matrix
        while (i < non_zero1)
        {
            result[k][0] = spa_mat1[i][0];
            result[k][1] = spa_mat1[i][1];
            result[k][2] = spa_mat1[i][2];
            i++;
            k++;
        }

        // Add remaining elements of the second matrix
        while (j < non_zero2)
        {
            result[k][0] = spa_mat2[j][0];
            result[k][1] = spa_mat2[j][1];
            result[k][2] = spa_mat2[j][2];
            j++;
            k++;
        }

        // Print the result
        printf("Resultant Sparse Matrix:\nR C Element\n");
        for (int i = 0; i < k; i++)
        {
            printf("(%d %d %d)\n", result[i][0], result[i][1], result[i][2]);
        }
    }

int main()
{
    int non_zero1, non_zero2;
    printf("Enter the number of non-zero elements in the first sparse matrix: ");
    scanf("%d", &non_zero1);
    printf("Enter the number of non-zero elements in the second sparse matrix: ");
    scanf("%d", &non_zero2);

    int spa_mat1[non_zero1][3];
    printf("Enter the first sparse matrix in 3-tuple format in row, col, Element format:\n");
    for (int i = 0; i < non_zero1; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &spa_mat1[i][0], &spa_mat1[i][1], &spa_mat1[i][2]);
    }

    int spa_mat2[non_zero2][3];
    printf("Enter the second sparse matrix in 3-tuple format in row, col, Element format:\n");
    for (int i = 0; i < non_zero2; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &spa_mat2[i][0], &spa_mat2[i][1], &spa_mat2[i][2]);
    }

    add_sparse(spa_mat1, spa_mat2, non_zero1, non_zero2);
}
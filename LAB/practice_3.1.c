// 3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.
#include <stdio.h>

void transpose(int smat_tuple[][3], int non_zero)
{
int i, j, k, n;
sp2[0][0] = sp1[0][1]; sp2[0][1] = sp1[0][0];
sp2[0][2] = sp1[0][2];
k = 1; n = b1[0][2];
for(i=0; i<sp1[0][1]; i++) {
for(j=1; j<=n; j++) {
if(i == sp1[j][1]) {
sp2[k][0] = i;
sp2[k][1] = sp1[j][0];
sp2[k][2] = sp1[j][2];
k++;
}
} }
}

    printf("The transpose of the sparse matrix is: \nR C Element\n");
    for (int i = 0; i <= non_zero; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d", trans[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col, non_zero, k = 0;
    printf("Enter the number non-zero elements of the sparse matrix: ");
    scanf("%d", &non_zero);

    int smat_tuple[non_zero + 1][3];
    printf("Enter the elements of the sparse matrix in tuple format: \n");
    for (int i = 0; i < non_zero; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &smat_tuple[i][j]);
        }
    }

    printf("The sparse matrix in tuple format is: \n");

    for (int i = 0; i < non_zero; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d", smat_tuple[i][j]);
        }
        printf("\n");
    }

    transpose(smat_tuple, non_zero);
}
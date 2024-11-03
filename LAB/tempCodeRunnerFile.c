//Wap to print sparse matrix in triplet form

#include<stdio.h>
#include<stdlib.h>


int main()
{
    int r,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);
    int arr[r][c];
    printf("Enter the elements: ");
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    int sparse[count+1][3];
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = count;
    int k = 1;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(arr[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
    printf("Sparse matrix in triplet form: \n");
    for(int i = 0; i<count+1; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
    return 0;
}

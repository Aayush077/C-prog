//sparse matrix in tuple form using 2-D array
#include<stdio.h>

int main()
{
    int row,col,i,j;
    printf("Enter the number of rows and columns of the sparse matrix: ");
    scanf("%d %d",&row,&col);
    int smat[row][col];
    printf("Enter the elements of the sparse matrix: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&smat[i][j]);
        }
    }
    printf("The sparse matrix is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf(" %d",smat[i][j]);
        }
        printf(" \n");
    }
    int k,size =0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(smat[i][j] != 0)
            {
                size++;
            }
        }
    }


    int smat_tuple[size+1][3];
    k=0;
    smat_tuple[k][0]=row;
    smat_tuple[k][1]=col;
    smat_tuple[k][2]=size;
    k++;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(smat[i][j] != 0)
            {
                smat_tuple[k][0]=i;
                smat_tuple[k][1]=j;
                smat_tuple[k][2]=smat[i][j];
                k++;
            }
        }
    }

    printf("The sparse matrix in tuple form is: \n");
    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf(" %d",smat_tuple[i][j]);
        }
        printf(" \n");
    }
    return 0;

}



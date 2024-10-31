//Write a program to sort array of elements in ascending and descending order by insertion sort using function.

#include<stdio.h>
#include<stdlib.h>

void InsertionSortAsce(int arr[],int n)
{
    int i,j,k;
    for (i=1;i<n;i++)
    {
        k=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>k)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}

void InsertionSortDesc(int arr[],int n)
{
    int i,j,k;
    for (i=1;i<n;i++)
    {
        k=arr[i];
        j=i-1;
        while(j>=0 && arr[j]<k)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    InsertionSortAsce(arr,n);
    printf("Sorted array in ascending order: ");
    display(arr,n);

    InsertionSortDesc(arr,n);
    printf("Sorted array in descending order: ");
    display(arr,n);

    return 0;
    
}
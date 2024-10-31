//Write a program to sort array of elements in ascending and descending order by selection sort using function.

#include<stdio.h>

void SelectionSortAsce(int arr[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

void SelectionSortDesc(int arr[], int n)
{
    int i,j,max,temp;
    for(i=0;i<n-1;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[max])
            {
                max=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
}

void display(int arr[], int n)
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

    SelectionSortAsce(arr,n);
    printf("Sorted array in ascending order: ");
    display(arr,n);


    SelectionSortDesc(arr,n);
    printf("Sorted array in descending order: ");
    display(arr,n);
    return 0;
}
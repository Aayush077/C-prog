//Write a program to perform bubble sort on array of elements to arrange it in ascending and decending order using function.

#include<stdio.h>


void BubbleSortAsce(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void BubbleSortDece(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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

    BubbleSortAsce(arr,n);
    printf("Sorted array in ascending order: ");
    display(arr,n);

    BubbleSortDece(arr,n);
    printf("Sorted array in descending order: ");
    display(arr,n);

    return 0;
}
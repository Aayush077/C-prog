#include <stdio.h>

void display_array(int arr[], int size)
{
    printf("The elements of array are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_array(int arr[], int *size, int pos)
{
    if (pos > *size || pos < 0)
    {
        printf("INVALID POSITI0N!!");
    }
    else
    {
        for (int i = pos; i < *size - 1; i++)
        {
            arr[i - 1] = arr[i];
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element Deleted.");
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    display_array(arr, size);

    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    delete_array(arr,&size,pos);
    display_array(arr,size);
}
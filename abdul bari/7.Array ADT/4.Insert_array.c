#include <stdio.h>
#include <stdlib.h>

void display_array(int arr[], int size)
{
    printf("Element of array are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_array(int arr[], int *size, int pos, int e)
{
    if (pos > *size || pos < 0)
        printf("Invalid position!");

    else
        for (int i = *size; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
    arr[pos - 1] = e;
    (*size)++;
    printf("Element inserted.\n");
}

int main()
{
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    int arr[size + 100];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    display_array(arr, size);

    int e, pos;
    printf("Enter the element and position to insert: ");
    scanf("%d %d", &e, &pos);
    insert_array(arr, &size, pos, e);
    display_array(arr, size);
}
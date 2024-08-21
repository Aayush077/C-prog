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

void binarysearch_array(int arr[], int size, int e)
{
    int l = 0, h = size - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == e)
        {
            printf("The element is fount at position %d.", mid + 1);
            return;
        }
        else if (arr[mid] > e)
        {
            h = mid - 1;
        }
        else if (arr[mid] < e)
        {
            l = mid + 1;
        }
        else
        {
            printf("The element is not found.");
        }
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

    int e;
    printf("Enter the element to search: ");
    scanf("%d", &e);
    binarysearch_array(arr, size, e);
}
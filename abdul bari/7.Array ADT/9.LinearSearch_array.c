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
void LinearSearch(int arr[], int size, int e)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == e)
        {
            printf("The element is found.\n");
            return;
        }
    }
    printf("The element is not found.\n");
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the element of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    display_array(arr, size);

    int e;
    printf("Enter the element to be searched: ");
    scanf("%d", &e);
    LinearSearch(arr, size, e);
}
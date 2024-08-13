// menu driven
#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int *n, int element, int position)
{
    if (position > *n || position < 0)
        printf("The position is invalid.");
    else
    {
        for (int i = *n; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        (*n)++;
    }
}

void delete(int arr[], int *n, int position)
{
    if (position > *n || position < 0)
        printf("Position Invalid.");
    else
    {
        for (int i = position; i < *n; i++)
        {
            arr[i - 1] = arr[i];
            arr[i] = arr[i + 1];
        }
        (*n)--;
    }
}

void linearsearch(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            printf("The position is %d.", i + 1);
            return;
        }
        else
        {
            printf("Element not found!");
        }
    }
}

void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n ");
}

int main()
{
    int n, choice, element, position, arr[n + 100];
    printf("Enter the size of array : ");
    scanf("%d", &n);

    printf("Enter the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\nMENU\n 1.INSERT \n 2.DELETE \n 3.LINEAR SEARCH \n 4. TRAVERSE\n Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            insert(arr, &n, element, position);
            break;

        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            delete (arr, &n, position);
            break;

        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            linearsearch(arr, n, element);
            break;

        case 4:
            traverse(arr, n);
            break;

        default:
            printf("Invlid! please try again");
            break;
        }
    }
}
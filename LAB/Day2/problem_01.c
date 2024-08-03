/*2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */

#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int *n, int e, int pos)
{
    if (pos > *n || pos < 0)
    {
        printf("Invalid position!\n");
    }
    else
    {
        for (int i = *n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        (*n)++;
        printf("Element inserted.\n");
    }
}

void delete(int arr[], int *n, int pos)
{
    if (pos >= *n || pos < 0)
    {
        printf("Invalid position!\n");
    }
    else
    {
        for (int i = pos; i < *n - 1; i++)
        {
            arr[i - 1] = arr[i];
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Element deleted.\n");
    }
}

void linearSearch(int arr[], int n, int e)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == e)
        {
            printf("Element found at position: %d\n", i + 1);
            return;
        }
    }
    printf("Element not found.\n");
}

void traverse(int arr[], int n)
{
    printf("Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, c, e, pos, arr[n + 100];;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Element to insert: ");
            scanf("%d", &e);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert(arr, &n, e, pos);
            traverse(arr, n);
            break;
        case 2:
            printf("Enter Position to delete: ");
            scanf("%d", &pos);
            delete (arr, &n, pos);
            traverse(arr, n); 
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &e);
            linearSearch(arr, n, e);
            break;
        case 4:
            traverse(arr, n);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

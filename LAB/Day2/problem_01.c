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

void binSearch(int arr[], int n, int e)
{
    int l = 0, h = n - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == e)
        {
            printf("Element found at position: %d\n", mid + 1);
            return;
        }
        else if (arr[mid] < e)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
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
}

int main()
{
    int n, c, e, pos, arr[n + 100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n***MENU***\n1. Insert\n2. Delete\n3. Linear Search\n4. Binary Search\n5. Traverse\n6. Exit\nEnter option: ");
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
            printf("Enter element to search: ");
            scanf("%d", &e);
            binSearch(arr, n, e);
            break;
        case 5:
            traverse(arr, n);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

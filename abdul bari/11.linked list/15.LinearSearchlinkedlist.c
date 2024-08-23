#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create_linkedlist(int arr[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display_linkelist(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *linearsearch_linkedlist(struct Node *p, int e)
{
    while (p != NULL)
    {
        if (p->data == e)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int main()
{
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    create_linkedlist(arr, n);

    display_linkelist(first);

    int e;
    printf("Enter the element to be searched: ");
    scanf("%d", &e);
    struct Node *temp;
    temp = linearsearch_linkedlist(first, e);
    if (temp)
    {
        printf("Element %d is found at address %d\n", e, temp);
    }
    else
    {
        printf("Element %d is not found\n", e);
    }
}
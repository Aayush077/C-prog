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

void display_linkedist(struct Node *p)
{
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}

void sortedinsert_linkedlist(struct Node *p, int e)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = e;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < e)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d,&n");
    int arr[n];
    printf("Enter the elements in a sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    create_linkedlist(arr, n);
    display_linkedist(first);

    int e;
    printf("Enter the element: ");
    scanf("%d", &e);
    sortedinsert_linkedlist(first, e);
    display_linkedist(first);

    printf("\n");
    return 0;
}
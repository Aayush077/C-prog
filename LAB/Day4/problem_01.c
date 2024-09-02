/*4.1 Write a program to create a single linked list of n nodes and perform the following menu-based operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int n)
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct Node *p, int pos, int e)
{
    struct Node *t;
    if (pos < 0 || pos > count(p))
    {
        printf("Invalid position\n");
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = e;
    if (pos == 1 || pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void delete(struct Node *p, int pos)
{
    struct Node *q = NULL;
    int x = -1;

    if (pos < 0 || pos > count(p))
    {
        printf("Invalid position\n");
    }
    if (pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
}

int main()
{
    int n, c, pos, e;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    create(arr, n);
    display(first);

    while (1)
    {
        printf("\nMENU\n1.INSERT AT ANY POSITION\n2.DELETE.\n3.COUNT.\n4.TRAVERSE.\n5.Exit\nEnter Choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("Enter the element to insert: ");
            scanf("%d", &e);
            insert(first, pos, e);
            display(first);
            break;

        case 2:
            printf("Enter the postion to delete: ");
            scanf("%d", &pos);
            delete (first, pos);
            display(first);
            break;

        case 3:
            printf("The number of nodes are: %d\n", count(first));
            break;

        case 4:
            display(first);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid!!");
        }
    }
    return 0;
}
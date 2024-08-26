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
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
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
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p)
{
    int l = 0;
    while (p != NULL)
    {
        l++;
        p = p->next;
    }
    return 1;
}

void reverse_array(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse_pointer(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

void reverse_recursion(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse_recursion(p,p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    create(arr, n);
    display(first);
    reverse_array(first);
    display(first);
    reverse_pointer(first);
    display(first);
    reverse_recursion(NULL,first);
    display(first);

    return 0;
}
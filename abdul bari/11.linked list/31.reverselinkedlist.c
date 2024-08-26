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
        t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
}
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("Elements are %d", p->data);
        p = p->next;
    }
    printf("\n");
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
}
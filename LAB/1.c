/*Write a C program to get the n number of nodes from the end of a singly linked
list.
Original list:
1 3 5 11 15 8
Enter n: 3
Last 3 nodes are: 11 15 8
*/
/*
WAP in C to perform one bit circular left shit of a singly linked list.
Example:
Original list: 24 3 19 6
New list: 3 19 6 24
*/
/*
WAP in C to print the odd position nodes of a singly.
Example:
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

void fromlast(struct Node *p, int m)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (count == m || count > m)
        {
            printf("%d ", p->data);
        }
        p = p->next;
    }
    printf("\n");
}


void onebit(struct Node *p)
{
    p=first;
    while(first!=NULL)
    {
        first = first->next;
        printf("%d ",first->data);
    }
    printf("%d",p->data);
}

void odd(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (count % 2 != 0)
        {
            printf("%d ", p->data);
        }
        p = p->next;
    }
    printf("\n");
}


int main()
{
    int n;
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

    int m;
    printf("Enter the number of nodes from the end: ");
    scanf("%d", &m);

    fromlast(first,m);
    display(first);

    onebit(first);
    display(first);

    odd(first);
    display(first);

    return 0;
}



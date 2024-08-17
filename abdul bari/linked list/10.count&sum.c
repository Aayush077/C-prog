#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create_linkedlist(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[i];
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
void display_linkedlist(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void count_linkedlist(struct Node *p)
{
    int l=0; //l is used to count the number of nodes
    while(p) //loop will run till p is not NULL
    {
        l++;
        p=p->next;
    }
    printf("Number of nodes are: %d\n",l);
}
/*
void recursive_count_linkedlist(struct Node *p)
{
    if(p !-0)
        return recursive_count_linkedlist(p->next)+1;
    else
        return 0;
}
*/

void sum_linkedlist(struct Node *p)
{
    int s=0;
    while(p)
    {
        s = s+p->data;
        p=p->next;
    }
    printf("Sum of all nodes is: %d\n",s);
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    create_linkedlist(arr, n);

    display_linkedlist(first);

    count_linkedlist(first);

    //recursive_count_linkedlist(first);

    sum_linkedlist(first);

    return 0;
}
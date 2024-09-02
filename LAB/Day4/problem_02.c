/*
4.2 Perform following operations using function on the single linked list:
 i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int arr[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void search(struct Node *p,int e)
{
    while(p!=NULL)
    {
        if(p->data==e)
        {
            printf("Element %d is found\n",e);
            return;
        }
        p=p->next;
    }
    printf("Element %d is not found\n",e);
}

void sort(struct Node *p)
{
    struct Node *q;
    int temp;
    while(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}

void reverse(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main()
{
    int n, c, e;
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

    while(1)
    {
        printf("\nMENU\n1.Search an element\n2.Sort the list in ascending order\n3.Reverse the list\n4.Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &e);
                search(first, e);
                break;
            case 2:
                sort(first);
                display(first);
                break;
            case 3:
                reverse(first);
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
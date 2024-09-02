/*
5.1 Write a program to create a double linked list and perform the following menu-based operations on it:
i. insert an element at specific position 
ii. delete an element from specific position
iii. Traverse the list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create_doublylinkedlist(int arr[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->prev = first->next = NULL;
    last = first;

    for(int i = 1; i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display_doublylinkedlist(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int count_doublylinkedlist(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
    printf("\n");
}

void insert_doublylinkedlist(struct Node *p,int e,int pos)
{
    struct Node *t;
    if( pos < 0 || pos > count_doublylinkedlist(p))
    {
        printf("Invalid position\n");
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=e;
    if(pos==1||pos==0)
    {
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next!=NULL)
        {
            p->next->prev=t;
        }
        p->next = t;
    }
}

void delete_doublylinkedlist(struct Node *p,int pos)
{
    struct Node *q=NULL;
    int x=-1;
    if(pos<0 || pos>count_doublylinkedlist(p))
    {
        printf("Invalid position\n");
    }
    if(pos==1)
    {
        first=first->next;
        if(first!=NULL)
        {
            first->prev=NULL;
        }
        x=p->data;
        free(p);
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
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
    create_doublylinkedlist(arr,n);



    int choice,e,pos;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Count Nodes\n4.Traverse\n5.Exit\nEnter a choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &e);
                printf("Enter the position to insert: ");
                scanf("%d",&pos);
                insert_doublylinkedlist(first,e,pos);

                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                delete_doublylinkedlist(first,pos);

                break;
            
            case 3:
                int count = count_doublylinkedlist(first);
                printf("The number of Nodes is %d.\n",count);

                break;

            case 4:
                display_doublylinkedlist(first);

                break;
            case 5:
                exit(0);
            break;
            default:
                printf("Invalid!!");

        }
    }

    
}
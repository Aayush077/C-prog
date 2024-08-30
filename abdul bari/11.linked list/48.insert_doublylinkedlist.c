#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int arr[], int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=last->next;
        t->prev=last;
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

int count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void insert_doublylinkedlist(struct Node *p, int index,int x)
{
    struct Node *t; 
    if(index<0 || index>count(p))
    {
        return;
    }
    if(index==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
        {
            p->next->prev=t;
        }
        p->next=t;
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

    create(arr,n);
    display(first);
    int index,x;
    printf("Enter the index and element to be inserted: ");
    scanf("%d %d",&index,&x);
    insert_doublylinkedlist(first,index,x);
    display(first);

    return 0;
}
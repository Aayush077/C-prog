#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create_doublylinkedlist(int arr[],int n)
{
    struct Node *t,*last;
    first =(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->prev=last;
        t->next=last->next;
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

void delete(struct Node *p,int pos)
{
    struct Node *q;
    int x=-1;
    if(pos<0||pos>count(p))
    {
        printf("Invalid position.\n");
    }
    if(pos==1)
    {
        first=first->next;
        if(first)
        {
            first->prev=NULL;
        }
        x=p->data;
        free(p);
    }
    else
    {
        for (int i=0;i<pos-1;i++)
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
    printf("The deleted element is %d.\n",x);
}

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create_doublylinkedlist(arr,n);
    display(first);
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    delete(first,pos);
    display(first);
    return 0;

}
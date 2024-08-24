#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create_linkedlist(int arr[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display_linkedlist(struct Node *p)
{
    while(p!=NULL)
    {
        printf(" %d",p->data);
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

int delete_linkedlist(struct Node *p,int pos)
{
    struct Node *q=NULL;
    int x=-1; // to store the deleted element

    if(pos<1 || pos>count(p))
        return -1;
    if(pos==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int main()
{
    int n;
    printf("Enter the size of linked list: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create_linkedlist(arr,n);   
    display_linkedlist(first);

    int pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    printf("Deleted element is: %d\n",delete_linkedlist(first,pos));
    display_linkedlist(first);
    return 0;
}
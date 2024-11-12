#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i = 1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int B[],int n)
{
    struct Node *t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=B[0];
    second->next=NULL;
    last=second;

    for(int i = 1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=B[i];
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

void concat(struct Node *p, struct Node *q)
{
    third=p;               

    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=q;

}

//between merge and concat any one will work
void merge_linkedlist(struct Node *p,struct Node *q)
{
    struct Node *last;  //used for merging
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next = NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while( p && q )
    {
        if(p->data < q->data)
        {
        last->next=p;
        last = p;
        p=p->next;
        last->next=NULL;
        }
    
    else
        {
        last->next=q;
        last = q;
        q=q->next;
        last->next=NULL;
        }

    }
    if(p != NULL)last->next=p;
    if(q != NULL)last->next=q;
}


int main()
{
    int n;
    printf("Enter the number of elementsof 1st array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of 1st array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int m;
    printf("Enter the number of elements of 2nd array: ");
    scanf("%d",&m);
    int B[m];
    printf("Enter the elements of 2nd array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }


    create1(A,n);
    create2(B,m);
    printf("First Linked List: ");
    display(first);
    printf("Second Linked List: ");
    display(second);
    concat(first,second);
    printf("Concatenated Linked List: ");
    display(third);
    merge_linkedlist(first,second);
    printf("Merged Linked List: ");
    display(third);

    return 0;
}
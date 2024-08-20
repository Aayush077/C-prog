#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;

void create_linked(int arr[],int n)
{
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data = arr[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data =arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display_linked(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int count_linked(struct Node *p)
{
    int count =0;
    while(p!=NULL)
    {
        count ++;
        p=p->next;
    }
    return count;
    }



void insert_linked(struct Node *p, int index,int x)
{
    if (index < 0 || index > count_linked(p))
    {
        return;
    }
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next =first;
        first =t;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next = p->next;
        p->next = t;
    }


}

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    create_linked(arr,n);

    display_linked(first);

    count_linked(first);

    int index,x;
    printf("Enter the index and element to be inserted: ");
    scanf("%d %d",&index,&x);
    insert_linked(first,index,x);
    display_linked(first);
}
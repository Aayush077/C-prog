#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create_linkedlist(int arr[], int n)
{
    int i; //useful for scanning through array
    struct Node *t,*last; //*t is temporary node that will help create new node, *last is used to keep track of last node and add a new node at the end of linked list 
    first = (struct Node *)malloc(sizeof(struct Node)); //it will create new node and first will be pointing to it
    first->data = arr[0]; //first node will have data of first element of array
    first->next =NULL; //next of first node will be NULL
    last = first; //last will be pointing to first node

    for(i=1;i<n;i++) //loop will start from 1 as first node is already created
    {
        t = (struct Node *)malloc(sizeof(struct Node));// creating new node
        t->data =arr[i]; //new node will have data of ith element of array
        t->next =NULL; //next of new node will be NULL
        last->next = t; //last node will point to new node
        last = t; //last will be pointing to new node
    }
}
void display_LinkedList(struct Node *p)
{
    while( p !=NULL)
    {
        printf(" %d",p->data);
        p=p->next;
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

    create_linkedlist(arr,n);
    display_LinkedList(first);

    return 0;
}
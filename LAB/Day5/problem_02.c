/*
5.2 Write a program to create a circular linked list and display the elements of the list.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void circular_linkedlist(int arr[],int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = first;
    last = first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=last->next;
        last->next = t;
        last = t;
    }
}

void display_circularlinkedlist(struct Node *p)
{
    if(p==NULL)
    {
        printf("List is empty\n");
    }
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=first);
    
}



int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter info of node %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    circular_linkedlist(arr,n);
    display_circularlinkedlist(first);

    return 0;
}
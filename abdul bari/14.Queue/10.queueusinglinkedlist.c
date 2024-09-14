#include<stdio.h>
#include<stdlib.h> 

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data =x;
        t->next =NULL;
        if(front == NULL)
        {
            front = rear =t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node *t;

    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x=front->data;
        t=front;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main()
{
    int size,x;
    printf("Enter the size of queue: ");
    scanf("%d",&size);
    printf("Enter the element of queue: ");

    for(int i=0;i<size;i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    display();

    printf("Dequeued element: %d\n",dequeue());
    display();
    return 0;
}
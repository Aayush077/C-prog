/*
WAP a menu driven program to implement a circular queue. The menu should have the following options:
1. Enqueue
2. Dequeue
3. IsEmpty
4. IsFull
5. Display
6. Exit
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front =NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = rear =t;
            rear->next = front;
        }
        else
        {
            rear->next = t;
            rear = t;
            rear->next = front;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        x = front->data;
        if(front == rear)
        {
            free(front);
            front = rear = NULL;
        }
        else
        {
            t = front;
            front = front->next;
            rear->next = front;
            free(t);
        }
    }
    return x;
}

int isEmpty()
{
    if(front == NULL)
        {
            printf("Queue is empty\n");
        }
    else
        {
            printf("Queue is not empty\n");
        }
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");
    free(t); 
    return 0;
}

void display()
{
    struct Node *p = front;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }while(p != front);
    printf("\n");
}

int main()
{
    int choice, x;
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                x = dequeue();
                if(x != -1)
                    printf("Deleted element is: %d\n", x);
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
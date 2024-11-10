/*WAP a menu driven program to implement a queue using array. The menu should have the following options:
1. Enqueue
2. Dequeue
3. Display
4.IsFull
5.IsEmpty
6.Exit
*/

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; 
};

void enqueue(struct Queue *q, int x)
{
    if(q->rear == q->size -1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

void rev(struct queue *q, int k)
{
    int i = q->front +1;
    for(int j= k; j>=i;j--)
    {
        printf("%d ", q->Q[j])
    }
}

int dequeue (struct Queue *q)
{
    int x=-1;

    if(q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    for(int i = q.front+1; i<=q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int isFull(struct Queue q)
{
    if(q.rear == q.size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
}

int isEmpty(struct Queue q)
{
    if(q.front == q.rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

int main()
{
    struct Queue q;
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    q.size = size;
    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size*sizeof(int));
    int choice;
    int x;
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. IsFull\n5. IsEmpty\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &x);
                enqueue(&q, x);
                break;
            case 2:
                printf("The element dequeued is: %d\n", dequeue(&q));
                break;
            case 3:
                display(q);
                break;
            case 4:
                isFull(q);
                break;
            case 5:
                isEmpty(q);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


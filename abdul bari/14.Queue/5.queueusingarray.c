#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; //
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

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

int main()
{
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    printf("Enter the elements of the queue: ");
    struct Queue q;
    create(&q, size);
    for(int i=0; i<size; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }
    display(q);

    printf("Dequeued element: %d\n", dequeue(&q));
    display(q);
    return 0;
}


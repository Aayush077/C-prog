#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void initialize(struct DEQueue *deq, int size)
{
    deq->size = size;
    deq->front = -1;
    deq->rear = -1;
    deq->Q = (int *)malloc(deq->size * sizeof(int));
}

void destroy(struct DEQueue *deq)
{
    free(deq->Q);
}

int isEmpty(struct DEQueue *deq)
{
    return deq->front == deq->rear;
}

int isFull(struct DEQueue *deq)
{
    return deq->rear == deq->size - 1;
}

void enqueueFront(struct DEQueue *deq, int x)
{
    if (deq->front == -1)
    {
        printf("DEQueue Overflow\n");
    }
    else
    {
        deq->Q[deq->front] = x;
        deq->front--;
    }
}

void enqueueRear(struct DEQueue *deq, int x)
{
    if (isFull(deq))
    {
        printf("DEQueue Overflow\n");
    }
    else
    {
        deq->rear++;
        deq->Q[deq->rear] = x;
    }
}

int dequeueFront(struct DEQueue *deq)
{
    int x = -1;
    if (isEmpty(deq))
    {
        printf("DEQueue Underflow\n");
    }
    else
    {
        x = deq->Q[deq->front];
        deq->front++;
    }
    return x;
}

int dequeueRear(struct DEQueue *deq)
{
    int x = -1;
    if (deq->rear == -1)
    {
        printf("DEQueue Underflow\n");
    }
    else
    {
        x = deq->Q[deq->rear];
        deq->rear--;
    }
    return x;
}

void display(struct DEQueue *deq)
{
    for (int i = deq->front + 1; i <= deq->rear; i++)
    {
        printf("%d", deq->Q[i]);
        if (i < deq->rear)
        {
            printf(" <- ");
        }
    }
    printf("\n");
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    struct DEQueue deq;
    initialize(&deq, sizeof(A) / sizeof(A[0]));

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        enqueueRear(&deq, A[i]);
    }
    display(&deq);
    enqueueRear(&deq, 11);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        dequeueFront(&deq);
    }
    dequeueFront(&deq);

    printf("\n");

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    {
        enqueueFront(&deq, B[i]);
    }
    display(&deq);
    enqueueFront(&deq, 10);
    enqueueFront(&deq, 12);

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    {
        dequeueRear(&deq);
    }
    display(&deq);
    dequeueRear(&deq);
    dequeueRear(&deq);

    destroy(&deq);

    return 0;
}

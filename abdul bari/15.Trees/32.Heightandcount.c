#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front =q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if((q->rear+1)%q->size == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x =NULL;
    if(q->front ==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front +1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQueue(struct Queue q)
{
    return q.front == q.rear;
}

struct Node *root = NULL;

int count(struct Node *root)
{
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
    return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if(root == NULL)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x > y)
        return x+1;
    else
        return y+1;
}

void createTree()
{
    struct Node *p, *t; // p is for parent, t is for temporary
    int x;  
    struct Queue q; 
    create(&q, 100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data =x;
    root->lchild = root->rchild =NULL;
    enqueue(&q, root);

    while(!isEmptyQueue(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

int main()
{
    createTree();
    printf("Height of tree is %d\n", height(root));
    printf("Number of nodes in tree is %d\n", count(root));
    return 0;
}
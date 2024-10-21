#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x) {
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQueue(struct Queue q) {
    return q.front == q.rear;
}

struct Node *root = NULL;

// For iterative traversal
struct Stack {
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack* stk, int size) {
    stk->size = size;
    stk->top = -1;
    stk->S = (struct Node **)malloc(stk->size * sizeof(struct Node *));
}

bool isEmptyStack(struct Stack stk) {
    return stk.top == -1;
}

void push(struct Stack* stk, struct Node *x) {
    if (stk->top == stk->size - 1)
        printf("Stack is Full\n");
    else {
        stk->top++;
        stk->S[stk->top] = x;
    }
}

struct Node *pop(struct Stack *stk) {
    struct Node *x = NULL;
    if (stk->top == -1)
        printf("Stack Underflow\n");
    else {
        x = stk->S[stk->top--];
    }
    return x;
}

void createTree() {
    struct Queue q;
    create(&q, 100);
    struct Node *p, *t;
    int x;
    root = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter root value: ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmptyQueue(q)) {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Levelorder(struct Node *p) {
    struct Queue q;
    create(&q, 100);
    printf("%d ", p->data);
    enqueue(&q, p);

    while (!isEmptyQueue(q)) {
        p = dequeue(&q);
        if (p->lchild) {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild) {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

int height(struct Node *p) {
    int l = 0, r = 0;
    if (p == NULL)
        return 0;
    l = height(p->lchild);
    r = height(p->rchild);
    return l > r ? l + 1 : r + 1;
}

void iterativePreorder(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100);
    while (p || !isEmptyStack(stk)) {
        if (p) {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterativeInorder(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100);
    while (p || !isEmptyStack(stk)) {
        if (p) {
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterativePostorder(struct Node *t) {
    struct Stack stk;
    createStack(&stk, 100);
    long long int temp;
    while (t || !isEmptyStack(stk)) {
        if (t) {
            push(&stk, t);
            t = t->lchild;
        } else {
            temp = (long long int)pop(&stk);
            if (temp > 0) {
                push(&stk, (struct Node *)-temp);
                t = ((struct Node *)temp)->rchild;
            } else {
                printf("%d ", ((struct Node *)-temp)->data);
                t = NULL;
            }
        }
    }
    printf("\n");
}

int main() {
    createTree();
    printf("Preorder: ");
    Preorder(root);
    printf("\n");

    printf("Inorder: ");
    Inorder(root);
    printf("\n");

    printf("Postorder: ");
    Postorder(root);
    printf("\n");

    printf("Levelorder: ");
    Levelorder(root);
    printf("\n");

    printf("Iterative Preorder: ");
    iterativePreorder(root);
    printf("Iterative Inorder: ");
    iterativeInorder(root);
    printf("Iterative Postorder: ");
    iterativePostorder(root);

    return 0;
}

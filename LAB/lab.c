#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int size;
    int top;
    int *arr;
} st,st1,st2;

int isEmpty(struct stack *st)
{
    if(st->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *st)
{
    if(st->top == st->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *st, int x)
{
    if(isFull(st))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->arr[st->top] = x;
    }
}

int pop(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int x = st->arr[st->top];
        st->top--;
        return x;
    }
}
void enqueue(int arr[st2->top])
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

void display(struct stack *st)
{
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

void Queueusingtwostack(struct stack *st1, struct stack *st2, int arr)
{
    for(int i = st1->top;i>=0; i--)
    {
        int x = pop(arr[st1->top]);
        push(x);
        top--;
    }
    for(int i = st2->top;i>=0;i--)
    {
        enqueue(arr[st2->top]);
        top--;
    }
}


int main()
{
    int n, value, choice;
    printf("Enter the size of the stack: ");
    scanf("%d", &st.size);
    st.arr = (int *)malloc(st.size * sizeof(int));
    st.top = -1;
    while(1)
    {
        printf("1. Push\n2. Pop\n3. Check stack is empty or not\n4. Check stack is full or not\n5. Display stack elements\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&st, value);
                break;
            case 2:
                printf("Popped element is: %d\n", pop(&st));
                break;
            case 3:
                if(isEmpty(&st))
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Stack is not empty\n");
                }
                break;
            case 4:
                if(isFull(&st))
                {
                    printf("Stack is full\n");
                }
                else
                {
                    printf("Stack is not full\n");
                }
                break;
            case 5:
                display(&st);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

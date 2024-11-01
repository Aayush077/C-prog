#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return top == NULL;
}

void display()
{
    struct Node *p = top;
    if (isEmpty())
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements: ");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n1. Push\n2. Pop\n3. IsEmpty\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is: %d\n", pop());
            break;
        case 3:
            if (isEmpty())
                printf("Stack is Empty\n");
            else
                printf("Stack is not Empty\n");
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

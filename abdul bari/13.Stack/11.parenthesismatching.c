#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

void pop()
{
    struct Node *t;
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
}

void display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                printf("Unbalanced\n");
                return;
            }
            pop();
        }
    }
    if (top == NULL)
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Unbalanced\n");
    }
}

int main()
{
    char exp[50];
    printf("Enter an expression: ");
    scanf("%s", exp);

    isBalanced(exp);
    
    return 0;
}
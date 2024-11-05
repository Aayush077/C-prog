#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
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

char pop()
{
    struct Node *t;
    char x = -1;
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
    return x;
}

void display()
{
    struct Node *p = top;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

int isoperand(char x)
{
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

char *Topostfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            while (top != NULL && pre(infix[i]) <= pre(top->data))
            {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char exp[50];
    printf("Enter an expression: ");
    scanf("%s", exp);

    char *postfix = Topostfix(exp);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);  // Free the dynamically allocated memory

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack *st)
{
    int i;
    for (i = st->top; i >= 0; i--)
    {
        printf("%d ", st->S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int main()
{
    struct Stack st;
    int n, value, choice;

    create(&st);

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);

    printf("Enter value to push: ");

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        push(&st, value);
    }

    printf("Stack elements after pushing %d elements: ", n);
    display(&st);

    printf("Do you want to pop an element? (1 for Yes / 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Popped element: %d\n", pop(&st));
        printf("Stack elements after popping: ");
        display(&st);
    }

    return 0;
}

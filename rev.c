// wap for reversing a string using stack



#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    char *S;
};

// Function to create a stack

void create(struct Stack *st) {
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (char *)malloc(st->size * sizeof(char));
}

// Function to push an element into the stack
void push(struct Stack *st, char x) {
    if(st->top == st->size - 1)
        printf("Stack overflow\n");
    else
        st->S[++st->top] = x;
}


// Function to pop an element from the stack
char pop(struct Stack *st) {
    char x = '0';
    if(st->top == -1)
        printf("Stack underflow\n");
    else
        x = st->S[st->top--];
    return x;
}

// Function to check if the stack is empty
int isEmpty(struct Stack st) {
    return st.top == -1;
}

// Function to reverse a string

void Reverse(char *exp) {
    struct Stack st;
    create(&st);
    for(int i = 0; exp[i] != '\0'; i++)
        push(&st, exp[i]);
    for(int i = 0; exp[i] != '\0'; i++)
        exp[i] = pop(&st);
}



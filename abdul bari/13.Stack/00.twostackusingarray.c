//WAP two stack using array;

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top1;
    int top2;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->S = (int *)malloc(st->size * sizeof(int));
    st->top1 = -1;
    st->top2 = st->size;
}

void Display(struct Stack st)
{
    int i;
    for (i = 0; i <= st.top1; i++)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
    for (i = st.size - 1; i >= st.top2; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void Push1(struct Stack *st, int x)
{
    if (st->top1 + 1 == st->top2)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top1++;
        st->S[st->top1] = x;
    }
}


void Push2(struct Stack *st, int x)
{
    if (st->top1 + 1 == st->top2)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top2--;
        st->S[st->top2] = x;
    }
}


int Pop1(struct Stack *st)
{
    int x = -1;
    if (st->top1 == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = st->S[st->top1];
        st->top1--;
    }
    return x;
}

int Pop2(struct Stack *st)
{
    int x = -1;
    if (st->top2 == st->size)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = st->S[st->top2];
        st->top2++;
    }
    return x;
}

int Peek1(struct Stack st, int index)
{
    int x = -1;
    if (st.top1 - index + 1 < 0)
    {
        printf("Invalid index\n");
    }
    x = st.S[st.top1 - index + 1];
    return x;
}

int Peek2(struct Stack st, int index)
{
    int x = -1;
    if (st.top2 + index - 1 >= st.size)
    {
        printf("Invalid index\n");
    }
    x = st.S[st.top2 + index - 1];
    return x;
}


int StackTop1(struct Stack st)
{
    if (st.top1 == -1)
    {
        return -1;
    }
    return st.S[st.top1];
}


int StackTop2(struct Stack st)
{
    if (st.top2 == st.size)
    {
        return -1;
    }
    return st.S[st.top2];
}

int IsEmpty1(struct Stack st)
{
    return st.top1 == -1;
}

int IsEmpty2(struct Stack st)
{
    return st.top2 == st.size;
}


int IsFull(struct Stack st)
{
    return st.top1 + 1 == st.top2;
}


int main()
{
    int n;
    struct Stack st;
    Create(&st);
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) // Pushing elements in stack 1
    {
        Push1(&st, a[i]);
    }
    for (int i = 0; i < n; i++) // Pushing elements in stack 2
    {
        Push2(&st, a[i]);
    }
    Display(st);
    return 0;
    
}
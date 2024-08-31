#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size; // This will be used to store the size of stack
    int top; // This will be used to keep track of the top element of stack
    int *S; // This is the array which will be used to store the elements of stack
};

void create(struct Stack *st)
{
    printf("Enter the size of stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if(st->top==st->size-1)
    {
        printf("stack overflown.\n");
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("stack underflown.\n");
    }
    else
    {
        x=st->S[st->top--];
    }
    return x;
}


int main()
{   
    int n;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Stack st;
    create(&st);
    for(int i=0;i<n;i++)
    {
        push(&st,arr[i]);
    }
    display(st);

    return 0;
}
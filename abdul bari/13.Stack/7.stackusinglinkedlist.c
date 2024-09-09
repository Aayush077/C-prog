#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int n,value,choice;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d",&n);
    printf("Enter value to push: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        push(value);
    }
    printf("Stack elements after pushing %d elements: ",n);
    display();
    printf("Do you want to pop an element? (1 for Yes / 0 for No): ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Popped element: %d\n",pop());
        printf("Stack elements after popping: ");
        display();
    }
    return 0;

}
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void create(int arr[], int n)
{
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int isloop(struct Node* f)
{
    struct Node *p, *q;
    p = q = f;

    do{
        p = p->next;
        q = q->next;
        q = q?q->next:q;
    }while(p && q && p!=q);

    return p==q?1:0;
}


int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    create(arr,n);

    struct Node* t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    printf("%d\n",isloop(first));
    return 0;
}
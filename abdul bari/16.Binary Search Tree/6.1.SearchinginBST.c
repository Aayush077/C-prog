#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void insert(int key)
{
    struct Node *t =root;
    struct Node *r, *p;

    if(root==NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t!=NULL)
    {
        r=t;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;

    while(t!=NULL)
    {
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    inorder(root);
    printf("\n");
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    struct Node *temp = Search(key);
    if(temp!=NULL)
        printf("Element %d is found\n", temp->data);
    else
        printf("Element %d is not found\n", key);
    return 0;
}
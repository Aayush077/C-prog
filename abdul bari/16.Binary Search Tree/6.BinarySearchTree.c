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
    struct Node *r, *p; // r is for tailing pointer, p is for parent pointer

    if(root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return;
    }
    while (t!=NULL)
    {
        r=t;
        if(key <t->data)
        {
            t = t->lchild;
        }
        else if(key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }

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

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = a[0];
    root->lchild = root->rchild = NULL;
    for(int i=1; i<n; i++)
    {
        insert(a[i]);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}
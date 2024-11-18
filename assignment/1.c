/*
Write a program to create a binary search tree of n data elements using linked list and perform the following menu driven operations:
i. preorder traversal
ii. postorder traversal
iii. inorder traversal
iv. search an element
*/

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
    struct Node *t = root;
    struct Node *r,*p;

    if (root == NULL)
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
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
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
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Search(struct Node *p, int key)
{
    if (p == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (key == p->data)
    {
        printf("Element found\n");
        return;
    }
    else if (key < p->data)
    {
        Search(p->lchild, key);
    }
    else
    {
        Search(p->rchild, key);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        insert(arr[i]);
    }
    int choice;
    while(1)
    {
        printf("\n1. Preorder Traversal\n2. Postorder Traversal\n3. Inorder Traversal\n4. Search an element\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 2:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 4:
                printf("Enter the element to search: ");
                int key;
                scanf("%d", &key);
                Search(root, key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
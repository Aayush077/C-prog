/*perform the following menu driven operations on BST.
i. insert an element to the BST
ii. display the largest element
iii. display the smallest element
iv. height of a node
v. count number of leaf nodes
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert (int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
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

int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    if(x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int CountLeafNodes(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = CountLeafNodes(p->lchild);
    y = CountLeafNodes(p->rchild);
    if (p->lchild == NULL && p->rchild == NULL)
    {
        return x + y + 1;
    }
    return x + y;
}

int LargestElement(struct Node *p)
{
    while (p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p->data;
}

int SmallestElement(struct Node *p)
{
    while (p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p->data;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert an element\n2. Display the largest element\n3. Display the smallest element\n4. Height of a node\n5. Count number of leaf nodes\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int key;
            printf("Enter the element to be inserted: ");
            scanf("%d", &key);
            Insert(key);
            break;
        case 2:
            printf("The largest element is: %d\n", LargestElement(root));
            break;
        case 3:
            printf("The smallest element is: %d\n", SmallestElement(root));
            break;
        case 4:
            printf("The height of the node is: %d\n", Height(root));
            break;
        case 5:
            printf("The number of leaf nodes are: %d\n", CountLeafNodes(root));
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
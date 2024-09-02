#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *first = NULL;

void create(int arr[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->coeff = arr[0];
    first->exp = arr[1];
    first->next = NULL;
    last = first;

    for (int i = 2; i < n; i += 2)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->coeff = arr[i];
        t->exp = arr[i + 1];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%dx^%d ", p->coeff, p->exp);
        if (p->next != NULL)
        {
            printf("+ ");
        }
        p = p->next;
    }
    printf("\n");
}

void add(struct Node *p, struct Node *q)
{
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    last = first;
    while (p != NULL && q != NULL)
    {
        if (p->exp > q->exp)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->coeff = p->coeff;
            t->exp = p->exp;
            t->next = NULL;
            last->next = t;
            last = t;
            p = p->next;
        }
        else if (p->exp < q->exp)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->coeff = q->coeff;
            t->exp = q->exp;
            t->next = NULL;
            last->next = t;
            last = t;
            q = q->next;
        }
        else
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->coeff = p->coeff + q->coeff;
            t->exp = p->exp;
            t->next = NULL;
            last->next = t;
            last = t;
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->coeff = p->coeff;
        t->exp = p->exp;
        t->next = NULL;
        last->next = t;
        last = t;
        p = p->next;
    }
    while (q != NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->coeff = q->coeff;
        t->exp = q->exp;
        t->next = NULL;
        last->next = t;
        last = t;
        q = q->next;
    }
}

int main()
{
    int n, m;
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the coefficients and exponents: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &m);
    int arr2[m];
    printf("Enter the coefficients and exponents: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }

    create(arr1, n);
    display(first);
    struct Node *p = first;
    create(arr2, m);
    display(first);
    struct Node *q = first;

    add(p, q);
    display(first);

    return 0;
}  
/*
4.3 Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations.
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*first=NULL;

void create_poly(int poly[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->coeff = poly[0];
    first->exp = poly[1];
    first->next = NULL;
    last =first;

    for(int i=2;i<n;i=i+2)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->coeff = poly[i];
        t->exp = poly[i+1];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display_poly(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%dx^%d ",p->coeff,p->exp);
        if(p->next!=NULL)
        {
            printf("+ ");
        }
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int deg1, deg2, max_deg;
    printf("Enter the maximum degree of the 1st polynomial: ");
    scanf("%d",&deg1);

    int poly1[deg1+1];
    printf("Enter the coefficients of the 1st polynomial:\n");
    for(int i=0;i<=deg1;i++)
    {
        printf("Coefficient for x^%d: ",i);
        scanf("%d",&poly1[i]);
    }
    
    printf("Enter the maximum degree of the 2nd polynomial: ");
    scanf("%d",&deg2);
    
    int poly2[deg2+1];
    printf("Enter the coefficients of the 2nd polynomial:\n");
    for(int i=0;i<=deg2;i++)
    {
        printf("Coefficient for x^%d: ",i);
        scanf("%d",&poly2[i]);
    }

    create_poly(poly1,deg1);
    display_poly(first);
    struct Node *p=NULL;
    create_poly(poly2,deg2);
    display_poly(first);
    struct Node *q=NULL;

}
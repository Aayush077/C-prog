#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create_linkedlist(int arr[], int n)
{
    int i;                                              
    struct Node *t, *last;                              
    first = (struct Node *)malloc(sizeof(struct Node)); 
    first->data = arr[0];                               
    first->next = NULL;                                 
    last = first;                                      
    for (i = 1; i < n; i++) 
    {
        t = (struct Node *)malloc(sizeof(struct Node)); 
        t->data = arr[i];                               
        t->next = NULL;                                
        last->next = t;                                 
        last = t;                                       
    }
}


void display_LinkedList(struct Node *p)
{
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
}



int count_linked(struct Node *p)
{
    int count =0;
    while(p!=NULL)
    {
        count ++;
        p=p->next;
    }
    return count;
    }



void insert_linked(struct Node *p, int index,int x)
{
    if (index < 0 || index > count_linked(p))
    {
        return;
    }
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next =first;
        first =t;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next = p->next;
        p->next = t;
    }


}


void insert_first(struct Node *p,int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next =first;
    first =t;
    
}


void insert_last(struct Node *p, int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    struct Node *head = p;
    while(p->next != NULL)
    {
        head=head->next;
    }
    head->next = t;
    t->next = NULL;
    
}


int main()
{
    int n,c,index,x;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    create_linkedlist(arr, n);
    display_LinkedList(first);

  

    while (1)
    {
          printf("\nMENU\n1.INSERT AT ANY POSITION\n2.INSERT AT FIRST\n3.INSERT AT LAST\n4.Display\n5.Exit\nEnter Choice: ");
             scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the index and element to insert: ");
                scanf("%d %d",&index,&x);
                insert_linked(first,index,x);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert_first(first,x);
                display_LinkedList(first);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert_last(first,x);
                display_LinkedList(first);
                break;

            case 4:
                display_LinkedList(first);
                break;

            case 5:
            exit(0);

            default:
                printf("Invalid!!");
        }
    }
    

    return 0;
}
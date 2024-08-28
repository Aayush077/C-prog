#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create_doublylinkedlist(int arr[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->prev = first->next = NULL;
    last = first;

    for(int i = 1; i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display_doublylinkedlist(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int count_doublylinkedlist(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
    printf("\n");
}

void insert_doublylinkedlist(int arr[],int *n,int e,int pos)
{
    if( index < 0 || index > count(p))
}

void delete_doublylinkedlist(int arrr[],int *n,int pos)
{

}


int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    create_doublylinkedlist(arr,n);



    int choice,e,pos;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Count Nodes\n4.Traverse\n5.Exit\nEnter a choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &e);
                printf("Enter the position to insert: ");
                scanf("%d",&pos);
                insert_doublylinkedlist(arr,&n,e,pos);

                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                delete_doublylinkedlist(arr,&n,pos);

                break;
            
            case 3:
                int count = count_doublylinkedlist(first);
                printf("The number of Nodes is %d.\n",count);

                break;

            case 4:
                display_doublylinkedlist(first);

                break;
            case 5:
                exit(0);
            break;
            default:
                printf("Invalid!!");

        }
    }

    
}
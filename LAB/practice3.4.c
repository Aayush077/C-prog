/*
perform following operations using function on the single linked list:
 i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list

Sample Input/Output:

Enter number of nodes: 5
Enter the elements: 17  23  47 11  78  92  51
MENU:
1.Traverse
2. Search
3. Sort
4. Reverse
5. Exit

Enter the choice: 2
Enter element to be searched: 23
Element found at node-3
Enter the choice: 4
Reverse list: 51->92->78->11->47->23->66->17
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function prototypes
void insertAtEnd(Node **head, int data);
void traverseList(Node *head);
Node *searchElement(Node *head, int key);
void sortList(Node **head);
void reverseList(Node **head);

int main()
{
    Node *head = NULL;
    int choice, data, key;
    int numNodes;

    // Input the number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    // Input the elements and create the list
    printf("Enter the elements: ");
    for (int i = 0; i < numNodes; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    do
    {
        printf("MENU:\n");
        printf("1. Traverse\n");
        printf("2. Search\n");
        printf("3. Sort\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("List: ");
            traverseList(head);
            printf("\n");
            break;

        case 2:
            
            printf("Enter element to be searched: ");
            scanf("%d", &key);
            Node *result = searchElement(head, key);
            if (result)
            {
                printf("Element found at node-%d\n", result);
            }
            else
            {
                printf("Element not found\n");
            }
            break;

        case 3:
            sortList(&head);
            printf("List sorted\n");
            break;

        case 4:
            
            reverseList(&head);
            printf("List reversed\n");
            break;

        case 5:
         
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *last = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void traverseList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

Node *searchElement(Node *head, int key)
{
    Node *current = head;
    int index = 1;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return NULL;
}

void sortList(Node **head)
{
    if (*head == NULL)
        return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void reverseList(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

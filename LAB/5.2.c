#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* last = NULL;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter info of node%d: ", i + 1);
        scanf("%d", &data);

        temp = createNode(data);

        if (head == NULL) {
            head = temp;
        } else {
            last->next = temp;
        }

        last = temp;
    }

    if (last != NULL) {
        last->next = head;
    }

    return head;
}

void displayCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n;

    printf("Enter no.of nodes: ");
    scanf("%d", &n);

    struct Node* head = createCircularLinkedList(n);

    printf("The circular linked list is: ");
    displayCircularLinkedList(head);

    return 0;
}

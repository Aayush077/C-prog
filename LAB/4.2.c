#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int degree;
    struct Node* next;
} Node;

Node* createPolynomial(int maxPower);
void printPolynomial(Node* head);
Node* addPolynomials(Node* poly1, Node* poly2);
void appendNode(Node** head, int coefficient, int degree);

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;
    int maxPower;

    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower);
    poly1 = createPolynomial(maxPower);

    printf("Polynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower);
    poly2 = createPolynomial(maxPower);

    result = addPolynomials(poly1, poly2);

    printf("Polynomial-1: ");
    printPolynomial(poly1);
    printf("\n");

    printf("Polynomial-2: ");
    printPolynomial(poly2);
    printf("\n");

    printf("Sum of the polynomials: ");
    printPolynomial(result);
    printf("\n");

    return 0;
}

Node* createPolynomial(int maxPower) {
    Node* head = NULL;
    int i, coeff;

    for (i = maxPower; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) {  
            appendNode(&head, coeff, i);
        }
    }

    return head;
}

void printPolynomial(Node* head) {
    Node* current = head;

    while (current != NULL) {
        if (current->coefficient > 0 && current != head) {
            printf(" + ");
        }
        printf("%dx^%d", current->coefficient, current->degree);
        current = current->next;
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current1 = poly1;
    Node* current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->degree == current2->degree) {
            appendNode(&result, current1->coefficient + current2->coefficient, current1->degree);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->degree > current2->degree) {
            appendNode(&result, current1->coefficient, current1->degree);
            current1 = current1->next;
        } else {
            appendNode(&result, current2->coefficient, current2->degree);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        appendNode(&result, current1->coefficient, current1->degree);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        appendNode(&result, current2->coefficient, current2->degree);
        current2 = current2->next;
    }

    return result;
}

void appendNode(Node** head, int coefficient, int degree) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->degree = degree;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

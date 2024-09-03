#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int data;
    struct Node *next;
} *first = NULL;

void create_sparsematrix(int arr[][5], int m, int n) {
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->row = m;
    first->col = n;
    first->data = 0; // Placeholder for the number of non-zero elements
    first->next = NULL;
    last = first;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->row = i;
                t->col = j;
                t->data = arr[i][j];
                t->next = NULL;
                last->next = t;
                last = t;
                first->data++; // Increment the count of non-zero elements
            }
        }
    }
}

void display_sparsematrix(struct Node *p) {
    printf("Sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", p->row, p->col, p->data);
    p = p->next;
    while (p != NULL) {
        printf("%d %d %d\n", p->row, p->col, p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int arr[m][n];
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    create_sparsematrix(arr, m, n);
    display_sparsematrix(first);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *first = NULL, *second = NULL, *sum = NULL;

void create_poly(struct Node **poly, int degree, int coeffs[]) {
    struct Node *t, *last = NULL;

    for (int i = 0; i <= degree; i++) {
        if (coeffs[i] != 0) {  // Only create nodes for non-zero coefficients
            t = (struct Node *)malloc(sizeof(struct Node));
            t->coeff = coeffs[i];
            t->exp = i;
            t->next = NULL;

            if (*poly == NULL) {
                *poly = t;
                last = t;
            } else {
                last->next = t;
                last = t;
            }
        }
    }
}

void display_poly(struct Node *p) {
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

void add_polys(struct Node *p1, struct Node *p2) {
    struct Node **last = &sum;

    while (p1 != NULL || p2 != NULL) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->next = NULL;

        if (p2 == NULL || (p1 != NULL && p1->exp > p2->exp)) {
            t->coeff = p1->coeff;
            t->exp = p1->exp;
            p1 = p1->next;
        } else if (p1 == NULL || (p2 != NULL && p2->exp > p1->exp)) {
            t->coeff = p2->coeff;
            t->exp = p2->exp;
            p2 = p2->next;
        } else {
            t->coeff = p1->coeff + p2->coeff;
            t->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        *last = t;
        last = &t->next;
    }
}

int main() {
    int deg1, deg2;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);

    int poly1[deg1 + 1];
    printf("\nEnter the coefficients of the first polynomial:\n");
    for (int i = 0; i <= deg1; i++) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &deg2);

    int poly2[deg2 + 1];
    printf("\nEnter the coefficients of the second polynomial:\n");
    for (int i = 0; i <= deg2; i++) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    create_poly(&first, deg1, poly1);
    create_poly(&second, deg2, poly2);

    printf("\nFirst Polynomial: ");
    display_poly(first);

    printf("Second Polynomial: ");
    display_poly(second);

    add_polys(first, second);

    printf("Sum of Polynomials: ");
    display_poly(sum);

    return 0;
}

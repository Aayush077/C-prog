//wap to add two polynomial.
#include <stdio.h>

void addPoly(int arr1[], int arr2[], int sum[], int n) {
    for (int i = 0; i < n; i++) {
        sum[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int n;
    printf("Enter the size of arr: ");
    scanf("%d", &n);

    int arr1[n+1], arr2[n+1], sum[n+1];

    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arr2[i]);
    }

    addPoly(arr1, arr2, sum, n+1);

    printf("Polynomial is:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", sum[i]);
        if (i != 0) {
            printf("x^%d ", i);
        }
        if (i != n) {
            printf("+ ");
        }
    }

    return 0;
}

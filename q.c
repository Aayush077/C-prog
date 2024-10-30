#include<stdio.h>

void merge(int arr1[], int arr2[], int *a, int b) {
    for (int i = 0; i < b; i++) {
        arr1[*a] = arr2[i];
        (*a)++;
    }
}

int main()
{
    int a, b;
    printf("Enter the size of the first array: ");
    scanf("%d", &a);
    printf("Enter the size of the second array: ");
    scanf("%d", &b);

    int arr1[a];
    int arr2[b];

    printf("Enter the elements of the first array: ");
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array: ");
    for (int i = 0; i < b; i++) {
        scanf("%d", &arr2[i]);
    }

    merge(arr1, arr2, &a, b);

    printf("Merged array: ");
    for (int i = 0; i < a; i++) {
        printf("%d ", arr1[i]);
    }

    return 0;
}


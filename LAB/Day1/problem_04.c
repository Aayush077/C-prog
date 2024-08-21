#include <stdio.h>
struct Complex
{
    int real;
    int imag;
};
struct Complex add(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void multiply(struct Complex *c1, struct Complex *c2, struct Complex *result)
{
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

int main()
{
    struct Complex c1, c2, result;
    int choice;
    printf("Enter real and imaginary parts of complex number 1: ");
    scanf("%d %d", &c1.real, &c1.imag);
    printf("Enter real and imaginary parts of complex number 2: ");
    scanf("%d %d", &c2.real, &c2.imag);

    do
    {
        printf("\nMENU\n1. Addition\n2. Multiplication\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            result = add(c1, c2);
            printf("Sum = %d + %di\n", result.real, result.imag);
            break;
        case 2:
            multiply(&c1, &c2, &result);
            printf("Product = %d * %di\n", result.real, result.imag);
            break;
        case 3:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

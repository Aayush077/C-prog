// create an array of n element using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0; 
    }
    return 1;
}

int SumOfPrimes(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    int *arr;

    printf("Enter size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = SumOfPrimes(arr, n);
    printf("Sum of prime numbers: %d\n", sum);

    free(arr); // Free the dynamically allocated memory

    return 0;
}

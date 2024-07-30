// calculate income tax of the employee.
#include <stdio.h>
int main()
{
    int income;
    printf("Enter employee income amount: ");
    scanf("%d", &income);
    if (income < 250000)
    {
        printf("There is no tax.");
    }

    else if (250000 < income < 500000)
    {
        printf("The income tax of the employee is: %d.", ((income - 250000) * 5) / 100);
    }

    else if (500000 < income <= 1000000)
    {
        printf("The income tax of the employee is: %d.", (((500000 - 250000) * 5) / 100 + ((income - 500000) * 20) / 100));
    }

    else if (1000000 < income)
    {
        printf("The income tax of the employee is: %d.", (((500000 - 250000) * 5) / 100 + ((1000000 - 500000) * 20) / 100) + ((income - 1000000) * 30) / 100);
    }
}
#include <stdio.h>

struct Employee
{
    int emp_id;
    char name[100];
    char designation[100];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};

float calculate_gross_salary(float basic_salary, float hra_percent, float da_percent)
{
    return basic_salary + (basic_salary * hra_percent / 100) + (basic_salary * da_percent / 100);
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Emp-id: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA %%: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA %%: ");
        scanf("%f", &employees[i].da_percent);

        employees[i].gross_salary = calculate_gross_salary(employees[i].basic_salary, employees[i].hra_percent, employees[i].da_percent);
    }
    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Emp-id: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Gross Salary: %.2f\n", employees[i].gross_salary);
    }

    return 0;
}

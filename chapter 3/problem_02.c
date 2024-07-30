// WAP to determine whether a student has passed or failed.To pass total of 40% and 33% in each subject.

#include <stdio.h>
int main()
{
    float m1, m2, m3;
    printf("Enter the marks in first subject: ");
    scanf("%f", &m1);
    printf("Enter the marks in second subject: ");
    scanf("%f", &m2);
    printf("Enter the marks in third subject: ");
    scanf("%f", &m3);
    printf("The marks are %.2f, %.2f, %.2f.\n", m1, m2, m3);

    if (m1 < 33 || m2 < 33 || m3 < 33)
    {
        printf("You have failed due to less mark in individual subjects\n");
    }
    else if ((m1 + m2 + m3) / 3 < 40)
    {
        printf("You have failed due to less percentage.\n");
    }
    else
    {
        printf("You have passed.");
    }
}
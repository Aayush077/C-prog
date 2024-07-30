#include<stdio.h>
int main()
{
    int r,h;
    printf("Enter the radius of cylinder.\n");
    scanf("%d",&r);
    printf("Enter the height of cylinder.\n");
    scanf("%d",&h);
    printf("The are of the circle is %f.\n",3.14*r*r);
    printf("The are of the cylinder is %f.",3.14*r*r*h);
    return 0;
}
#include<stdio.h>
    
int main()
{
    int l,b,area;
    printf("Enter the length and breadth");
    scanf("%d %d", &l,&b);
    area = l*b;
    printf("Area of Rectangle is %d", area);
    return 0;
}
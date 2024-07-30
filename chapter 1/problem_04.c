//calculate simple intrest
#include<stdio.h>
int main()
    {
        int s,p,r,t;
        printf("Enter the principle amount \n");
        scanf("%d",&p);
        printf("Enter the rate of intrest \n");
        scanf("%d",&r);
        printf("Enter the time period \n");
        scanf("%d",&t);
        s = (p*t*r)/100;
        printf("The simple intrest of the principle amount is: %d \n", s);
    }
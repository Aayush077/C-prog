// celcius to farenheit
#include<stdio.h>
int main()
    {
        float c,f;
        printf ("Enter the temperature in celcius \n");
        scanf("%f",&c);
        f = ((9/5)*c)+32;
        printf("The temperature in farenheit is %f",f);
    }
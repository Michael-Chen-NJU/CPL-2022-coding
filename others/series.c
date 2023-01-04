//
// Created by HW on 2022/10/8.
//
#include <stdio.h>
#include <math.h>
int main()
{
    float x,y,a[10000]={0};
    int n;
    scanf("%f %d",&x,&n);
    for(int i = 0;i <=n; i++)
    {
        a[i] =pow(-1,i)*pow(x,2*i+1)/(2*i+1);
        y+=a[i];
    }
    y=4*y;
    printf("%.10lf",y);
}
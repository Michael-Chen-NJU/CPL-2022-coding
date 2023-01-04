//
// Created by HW on 2022/10/5.
//
#include<stdio.h>
int main()
{
    int n;
    int s=0,s3=0,s5=0,s7=0;
    scanf("%d",&n);
    while(n!=0)
    {
        if(n%3==0&&n%5==0&&n%7!=0)
            s++;
        else if(n%3!=0&&n%5==0&&n%7==0)
            s++;
        else if(n%3==0&&n%5!=0&&n%7==0)
            s++;
        else if(n%3==0&&n%5==0&&n%7==0)
            s++;
        else if(n%3==0&&n%5!=0&&n%7!=0)
        {
            s++;
            s3++;
        }
        else if(n%3!=0&&n%5==0&&n%7!=0)
        {
            s++;
            s5++;
        }
        else if(n%3!=0&&n%5!=0&&n%7==0)
        {
            s++;
            s7++;
        }
        else
            s++;
        scanf("%d",&n);
    }
    printf("%.2f%%\n",(float)s3*100/s);
    printf("%.2f%%\n",(float)s5*100/s);
    printf("%.2f%%\n",(float)s7*100/s);
    return 0;
}

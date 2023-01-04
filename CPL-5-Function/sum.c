//
// Created by HW on 2022/10/28.
//
#include <stdio.h>
#include <math.h>
int main()
{
    int n,t,sum = 0;
    int a[100]={0};
    scanf("%d %d",&n,&t);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            a[i] = a[i] + t * pow(10,j);
        }
        sum += a[i];
    }
    printf("%d",sum);
}

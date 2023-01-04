//
// Created by HW on 2022/11/19.
//
#include <stdio.h>
int main()
{
    int n;
    scanf("%x",&n);
    printf("%d\n",n);
    printf("%u\n",n);
    const float *fl = (float *) &n;
    printf("%.6f\n",*fl);
    printf("%.3e",*fl);
}
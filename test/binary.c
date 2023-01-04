//
// Created by HW on 2022/10/17.
//
#include <stdio.h>
int main()
{
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i=0;i<32;i++){
        a[i]=n%2;
        n=(n-a[i])/2;
    }
    for (int i = 31; i >=0 ; --i) {
        printf("%d",a[i]);
    }
    return 0;
}
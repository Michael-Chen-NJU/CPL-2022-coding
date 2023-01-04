//
// Created by HW on 2022/10/8.
//
#include <stdio.h>
int main()
{
    int n,j,max=n,a[1000],i=0;
    scanf("%d",&n);
    for(i = 0 ;n != 1 ;++i)
    {
        a[i]=n;
        if(n%2 == 0) {
            n = n / 2;
        }else{
            n = 3*n+1;
        }
      }
    max=a[0];
    for(int j = 0; j < i; j++) {
        if(max<=a[j]){
            max=a[j];
        }
    }
    printf("%d %d",i,max);
}
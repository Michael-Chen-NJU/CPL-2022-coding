//
// Created by HW on 2022/10/7.
//
#include <stdio.h>
int main()
{
    int n,i,j;
    int a[100005],b[100005]={0};
    scanf("%d\n",&n);
    for (int i = 0; i < (2*n-1); ++i) {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(int i=0;i<=(10*n); ++i){
        if(b[i]==1)
            printf("%d",i);
    }
    return 0;
}
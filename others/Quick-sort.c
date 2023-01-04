//
// Created by HW on 2022/10/16.
//
#include <stdio.h>
int main()
{
    int n,k,mid,t=0;
    int a[10000]={0};
    scanf("%d %d\n",&n,&k);
    int l=1,r=n;
    //输入
    for (int i = 1; i <=n ; ++i) {
        scanf("%d",&a[i]);
    }
    mid=a[k];
    //printf("%d",mid);

    //实现基本条件
    while(r!=l) {
        while (l != r && a[l] < mid) {
            l++;
        }
        while (l != r && a[r] >= mid){
            r--;
        }
        if (a[l]>mid&&a[r]<=mid) {
            t = a[l];
            a[l] = a[r];
            a[r] = t;
        }
//        else if(l==r&&a[r]>mid&&r<k){
//            t = a[l];
//            a[l] = a[r+1];
//            a[r+1] = t;
//            mid=a[l];
//        }
        else if(l==k&&a[l]!=a[r]){
            t = a[l];
            a[l] = a[r];
            a[r] = t;
            k=r;
        }
    }
    if(l==r&&l<k){
        t=a[l];
        a[l]=a[k];
        a[k]=t;
    }
    //输出
    for (int i = 1; i <= n ; ++i) {
        printf("%d ",a[i]);
    }
    return 0;
}

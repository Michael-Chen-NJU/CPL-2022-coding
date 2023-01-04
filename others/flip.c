//
// Created by HW on 2022/10/15.
//
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[2000]={0};
    for (int i = 0; i < n; ++i) {

        for (int j = 1; j <= n; ++j) {
            if((i+1)%j == 0){
                if(a[i]==0){
                    a[i]=1;
                }
                else if(a[i]==1){
                    a[i]=0;
                }
            }

            else{
                a[i]=a[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(a[i]==1){
            printf("%d ",i+1);
        }
    }
    return 0;
}
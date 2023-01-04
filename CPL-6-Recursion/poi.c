//
// Created by HW on 2022/11/5.
//
#include <stdio.h>
int f[10005]={0};
int Find (int x);
int main(void){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&f[i]);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", Find(i ));
    }
}
int Find(int x){
    if(f[x]==x){
        return x;
    }
    return Find(f[x]);
}
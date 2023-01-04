//
// Created by HW on 2022/10/15.
//
#include <stdio.h>

int main() {
    int n, k,i=1, kill=1, num;
    scanf("%d %d", &n, &k);
    int a[1000] = {0};

    for(;kill!=n;i++){
        if (i > n) {
            i = 1;
        }
        if (a[i] == 0) {
            num++;
        }
        if (num == k) {
            num = 0;
            a[i] = 1;
            kill++;
            //printf("%d ",i);
        }
    }

    for(int i=1;i<=n;i++) {
        if (a[i]!=1){
            printf("%d",i);
        }
    }
    return 0;
}
//
// Created by HW on 2022/10/9.
//
#include<stdio.h>
int main() {
    int n, k, i = 0;
    char a[10000],b[10000];
    scanf("%d", &n);
    getchar();
    for(i=0;i<n;i++){
        scanf("%c", &a[i]);
    }
    getchar();
   scanf("%d", &k);
   for(i=0;i<=(k-1);i++){
       b[i]=a[(k-1-i)];
       printf("%c", b[i]);
   }
   for(int i=k;(k<=i)&&(i<n);i++){
       b[i]=a[(n-1-i+k)];
       printf("%c", b[i]);
   }
    return 0;
}

//
// Created by HW on 2022/11/5.
//
#include <stdio.h>
long int n = 0;
int l;
int f[1000];
int ans[1000][2]={0};
void max(int x, int y);
int main()
{

    scanf("%ld",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&f[i]);
    }
    max (1 ,n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ",ans[i][j]);

        }
        printf("\n");
    }
}

void max(int x,int y){
int k = x;
    if(x + 1 == y){
        if(f[x] > f[y]){
            ans[x][0] = x;
            ans[x][1] = y;
            ans[y][0] = y;
            ans[y][1] = y;
        }
        else{
            ans[x][0] = x;
            ans[x][1] = x;
            ans[y][0] = x;
            ans[y][1] = y;
        }
    }
    if(x == y){
        ans[k][0] = x;
        ans[k][1] = x;
    }
    else if(x < y){

        for (int i = x; i < y; ++i) {
            if (f[i] > f[i + 1]) {
                l = i;
            } else {
                l = i + 1;
            }
            if(f[l] > f[k]){
                k = l;
            }
            else{
                k = k;
            }
        }
        ans[k][0] = x;
        ans[k][1] = y;
        max(x, k - 1);
        max(k + 1, y);
    }
}
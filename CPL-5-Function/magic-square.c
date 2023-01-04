//
// Created by HW on 2022/10/29.
//
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    scanf("%d",&n);
    int row=0,col=(n-1)/2;
    int a[10][10]={0};
    bool b[10][10]={0};
    int count [10]={0};
    a[row][col] = 1;
    b[row][col] = 1;
    for (int i = 2; i <= n*n; ++i) {
        //上出界
        if((row)-1 < 0 &&(col+1) <n&&count[i]==0){
            row=n-1;
            col++;
            if(b[row][col]==1){
                row=1;
                col--;
            }
            a[row][col]=i;
            b[row][col]=1;
            count[i]++;
        }
        //右出界
        if((row)-1 >= 0 &&(col+1) >= n&&count[i]==0){
            row=row - 1;
            col=0;
            if(b[row][col]==1){
                col=n-1;
                row=row+2;
            }
            a[row][col]=i;
            b[row][col]=1;
            count[i]++;
        }
        //右上出界
        if((row)-1 < 0&&(col+1) >= n&&count[i]==0){
            row=n-1;
            col=0;
            if(b[row][col]==1){
                row=1;
                col=n-1;
            }
            a[row][col]=i;
            b[row][col]=1;
            count[i]++;
        }
        //不出界
        if((row)-1 >= 0 &&(col+1) <n&&count[i]==0){
            row--;
            col++;
            if(b[row][col]==1){
                row=row+2;
                col--;
            }
            a[row][col]=i;
            b[row][col]=1;
            count[i]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

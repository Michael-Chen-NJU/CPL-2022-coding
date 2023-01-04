//
// Created by HW on 2022/10/28.
//
#include <stdio.h>

int main()
{
    int n,m=1,t;
    int array[2000]={0},count=0,b[2000]={0};
    int pk=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i]);
    }
    //找出给出的排列的最长连续递降后缀，其长度记为 m
    for (int i = n-1; i >0; --i) {
        if(array[i]<array[i-1]){
            m++;
        }
        else if(array[i]>array[i-1]){
            pk=n-1-m;
            break;
        }
    }
            //printf("%d %d ",pk,m);

//找到最长递降后缀的之前的那个数，记为 pk在最长递降后缀中找到大于pk的数中最小的那个，交换这两个数。
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(count==0) {
                if (array[(pk + j)] == (array[pk] + i)) {
                    t = array[pk];
                    array[pk] = array[(pk + j)];
                    array[(pk + j)] = t;
                    count++;
                    //printf("%d %d",array[pk],array[pk+j]);
                }
            }
        }
    }
    //将交换后的序列的后 m个数翻转

    for (int i = 0; i < n-m; ++i) {
        printf("%d ",array[i]);
    }

    for(int i=n-m;i<n;i++){
        b[i]=array[(n-i+n-m-1)];
        printf("%d ", b[i]) ;
    }
}


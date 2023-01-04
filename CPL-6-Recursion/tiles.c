//
// Created by HW on 2022/11/5.
//
#include <stdio.h>
long long int Tiles(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld", Tiles(n));
}
long long int Tiles(int n){
    if(n == 1 || n ==2){
        return n;
    }
    return Tiles(n - 1)+Tiles(n - 2);
}
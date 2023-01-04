//
// Created by HW on 2022/10/28.
//
#include <stdio.h>
#include <stdbool.h>

int System_Reverse(int n,int S);

int main()
{
    int p,q,r,new_r=0;
    bool is_S = 0;
    scanf("%d %d %d",&p,&q,&r);
    int a,b,c;
    if(r >= 10) {
        a = r / 10;
        b = r - a * 10;
            if(a >= b){
                c = a + 1;
            }
            if(a < b){
                c = b + 1;
            }
    }
    if(r < 10){
        c = r + 1;
    }
    for (int S = c; S <= 40; ++S) {

        new_r = System_Reverse(r,S);
        if(p*q == new_r){
            printf("%d",S);
            is_S = 1;
            break;
        }
    }

    if(!is_S){
        printf("0");
    }
}

int System_Reverse(int n,int S){
    int a, b;
    if(n >= 10){
        a = n /10;
        b = n - a * 10;
        return b + a * S;
    }
    return n;
}
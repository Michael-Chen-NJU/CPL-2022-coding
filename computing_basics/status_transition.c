//
// Created by HW on 2022/10/29.
//
#include <stdio.h>
int main()
{
    int s0,i,n,t,o;
    scanf("%d %d %d %d %d",&s0,&i,&n,&t,&o);
    for(int j=0;j<1;j++) {
        if (s0 == 0) {
            if (o == i) {
                s0 = 1;
                break;
            } else {
                s0 = 0;
                break;
            }
        }
        if (s0 == 1) {
            if (o == i) {
                s0 = 1;
                break;
            } else if (o == n) {
                s0 = 2;
                break;
            } else {
                s0 = 0;
                break;
            }
        }
        if (s0 == 2) {
            if (o == i) {
                s0 = 1;
                break;
            } else if (o == t) {
                s0 = 3;
                break;
            } else {
                s0 = 0;
                break;
            }
        }
        if (s0 == 3) {
            if (o == i) {
                s0 = 1;
                break;
            } else {
                s0 = 0;
                break;
            }
        }
    }
    printf("%d",s0);
}
//
// Created by HW on 2022/10/16.
//
#include <stdio.h>
int main() {
    int n,k=0,count=0;
    int a[200000];
    int b[200]={0};
    //shu zu
    for (int i = 0,j=0; j < 100; i+=2,j++) {
        b[i]=j/10;
        b[i+1]=j%10;
        //printf("%d%d ",b[i],b[i+1]);
    }
    //shu ru
    scanf("%d\n", &n);
    for (int i = 0; i <= n; ++i) {
        scanf("%c", &a[i]);
    }

    //fen qing kuang
    for (int i = 0; i <= n; ++i) {
        if (a[i] != '?') {
            printf("%c", a[i]);
        } else if (a[i] == '?') {
            int j = n - 1 - i;
            if (a[j] != '?') {
                a[i] = a[j];
                printf("%c", a[i]);
            } else if (a[j] == '?') {
                if(i<j) {
                    for(;k < 200;) {
                        printf("%d%d", b[k], b[k + 1]);
                        k=k+2;
                        count++;
                        break;
                    }
                }
                else if(i>j) {
                    for(;k >0;) {
                        printf("%d%d", b[k-1], b[k-2]);
                        k-=2;
                        break;
                    }
                }
            }
        }
    }


//    bool is_palindrome =true;

//            is_palindrome = false;
//            break;
//        }
}
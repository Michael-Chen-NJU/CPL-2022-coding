//
// Created by HW on 2022/10/15.
//
#include <stdio.h>
int main() {
    int n;
    char a[100001];
    int b[256],c[256];
    scanf("%d\n", &n);
    int count=0;
    for (int i = 0; i < n; ++i) {
        scanf("%c", &a[i]);
        b[a[i]]++;
        c[a[i]]++;
    }

    for (int k = n; k > 1; k--) {
        for (int j = 65; j <= 122; ++j) {
            while (c[j] == k) {

                for (int l = 97; l <= 122; ++l) {
                    if (c[l] != 0 && c[l] != k) {
                        printf("\ ");
                    } if(c[l] != 0 && c[l] == k){
                        printf("=");
                        c[l]--;
                    }
                    if (c[l - 32] != 0 && c[l - 32] != k) {
                        printf("\ ");
                    }  if(c[l - 32] != 0 && c[l - 32] == k){
                        printf("=");
                        c[l-32]--;
                    }
                    if ((c[l] != 0 && c[l] != k) || (c[l - 32] != 0 && c[l - 32] != k)) {
                        printf("\ ");
                    }
                    if ((c[l] != 0 && c[l] == k) || (c[l - 32] != 0 && c[l - 32] == k)) {
                        printf("\ ");
                    }
                }
                printf("\n");

            }
        }
    }

    for (int k = 1; k > 0; ) {

                for (int l = 97; l <= 122; ++l) {
                    if (c[l] != 0 && c[l] != k) {
                        printf("\ ");
                        count++;
                    }  if(c[l] != 0 && c[l] == k){
                        printf("=");
                        count++;
                    }
                    if (c[l - 32] != 0 && c[l - 32] != k) {
                        printf("\ ");
                        count++;
                    } if(c[l - 32] != 0 && c[l - 32] == k){
                        printf("=");
                        count++;
                    }
                    if ((c[l] != 0 && c[l] != k) || (c[l - 32] != 0 && c[l - 32] != k)) {
                        printf("\ ");
                        count++;
                    }
                    if ((c[l] != 0 && c[l] == k) || (c[l - 32] != 0 && c[l - 32] == k)) {
                        printf("\ ");
                        count++;
                    }
                }
                printf("\n");
                break;
    }
    //print -
    for (int i = 1; i < count; ++i) {
        printf("-");
    }
        printf("\n");

        //print alphabet
        for (int j = 97; j <= 122; ++j) {

            if (b[j] != 0) {
                printf("%c", j);
            }
            if (b[j - 32] != 0) {
                printf("%c", j - 32);
            }
            if (b[j] != 0 || b[j - 32] != 0) {
                printf("\ ");
            }
        }
}
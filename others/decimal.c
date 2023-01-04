//
// Created by HW on 2022/10/16.
//
#include <stdio.h>
#include <math.h>
int main()
{
    int len, N, decimal=0,c=0;
    scanf("%d %d\n",&len,&N);
    char a[100]={0};
    //getchar();
    if(N <= 10) {
        for (int i = 0; i < len; ++i) {
            scanf("%c", &a[i]);
        }
        for (int i = 0; i < len; ++i) {
            if (a[i] >= 48) {
                //printf("%d ", a[i] - 48);
                if (a[i] - 48 < N) {
                    decimal += (a[i] - 48) * pow(N, (len-i-1));
                    //printf("%d ", decimal);
                } else if (a[i] - 48 >= N) {
                    printf("Error");
                    c=1;
                    break;
                }
            }
        }
       if(c==0){
           printf("%d",decimal);
       }
    }
    if(N > 10) {
        for (int i = 0; i < len; ++i) {
            scanf("%c", &a[i]);
        }
        for (int i = 0; i < len; ++i) {
            if (48 <= a[i]&&a[i] < 58){
                //printf("%d ", a[i] - 48);
                if (a[i] - 48 < N) {
                    decimal += (a[i] - 48) * pow(N, (len-i-1));
                    //printf("%d ", decimal);
                } else if (a[i] - 48 >= N) {
                    printf("Error");
                    c=1;
                    break;
                }
            }
            if(65 <= a[i]&&a[i] <= 90){
                //printf("%d ", a[i] - 55);
                if (a[i] - 55 < N) {
                    decimal += (a[i] - 55) * pow(N, (len - i - 1));
                    //printf("%d ", decimal);
                } else if (a[i] - 55 >= N) {
                    printf("Error");
                    c=1;
                    break;
                }
            }
        }
        if(c==0) {
            printf("%d", decimal);
        }
    }
}
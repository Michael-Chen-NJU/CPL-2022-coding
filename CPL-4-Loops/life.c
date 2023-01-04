//
// Created by HW on 2022/10/22.
//
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int count[1100]={0},COUNT[1100]={0};
    char str[1000];
    char new_str[1000];
    memset(new_str,'.',1000);
    scanf("%d",&n);
    getchar();
    scanf("%s",str);
    int len;
    len = strlen(str);
//    printf("%d",len);
//    printf("%c",str[0]);
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < len; ++i) {
            if (i >= 3 && i <= len - 4) {
                for (int j = i - 3; j < i ; ++j) {
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
                for(int j=i+1;j<=i+3;++j){
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            } else if (i == 0) {
                for(int j=i+1;j<=i+3;++j){
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            } else if (i == 1) {
                for (int j = i - 1; j < i ; ++j) {
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
                for(int j=i+1;j<=i+3;++j){
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            } else if (i == 2) {
                for (int j = i - 2; j < i ; ++j) {
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
                for(int j=i+1;j<=i+3;++j){
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            } else if (i == len - 1) {
                for (int j = i - 3; j < i ; ++j) {
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            } else if (i == len - 2) {
                for (int j = i - 3; j < i ; ++j) {
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
                for(int j=i+1;j<=i+1;++j){
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            } else if (i == len - 3) {
                for (int j = i - 3; j < i ; ++j) {
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
                for(int j=i+1;j<=i+2;++j){
                    if (str[j] == 'A') {
                        count[i]++;
                    } else if (str[j] == 'B') {
                        COUNT[i]++;
                    }
                }
            }
            if (str[i] == '.') {
                if (count[i] >= 2 && count[i] <= 4 && COUNT[i] == 0) {
                    new_str[i] = 'A';
                } else if (COUNT[i] >= 2 && COUNT[i] <= 4 && count[i] == 0) {
                    new_str[i] = 'B';
                }
            } else if (str[i] == 'A') {
                if (count[i] >= 5 || count[i] <= 1 || COUNT[i] > 0) {
                    new_str[i] = '.';
                } else {
                    new_str[i] = 'A';
                }
            } else if (str[i] == 'B') {
                if (COUNT[i] >= 5 || COUNT[i] <= 1 || count[i] > 0) {
                    new_str[i] = '.';
                } else {
                    new_str[i] = 'B';
                }
            }
        }
        for (int i = 0; i < len; ++i) {
            str[i]=new_str[i];
            //printf("%c",str[i]);
        }
        if(k < n-1) {
            memset(new_str, '.', 1000);
            memset(count,0,1100);
            memset(COUNT,0,1100);
//            for (int l = 0; l < len; ++l) {
//                printf("%c",new_str[l]);
//            }
        }
    }
    for (int i = 0; i < len; ++i) {
        printf("%c",new_str[i]);
    }

    }



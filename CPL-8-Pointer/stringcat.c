//
// Created by HW on 2022/11/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mystrcat(char *a, char *b);
int stringcompare(char *a,const char *b, int x);
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int i = 0; i < T; ++i) {
        char *x = (char *) malloc(sizeof(char) * 1005);
        char *y = (char *) malloc(sizeof(char) * 1005);
        scanf("%s",&(*x));
        scanf("%s",&(*y));
        mystrcat(x,y);
        free(x);
        free(y);
        getchar();
    }
}
void mystrcat(char *a, char *b){
    int index = 0;
    for (int j = 1; j <= strlen(b); ++j) {
        if(stringcompare(a,b,j) == 1){
            index = j;
        }
    }
    int len_b = strlen(b);
    for (int j = 0; j < index; ++j) {
        for (int i = 0; i < len_b; ++i) {
            *(b + i) = *(b + i + 1);
        }
    }
    printf("%s%s\n",a,b);
}
int stringcompare(char *a ,const char *b ,int x){

    int count = 0;
    int len_a = strlen(a);
    for (int i = 0; i < x; ++i) {
        if(*(a + len_a  - x + i) == *(b + i)){
            count ++;
        }
    }
    if(count == x){
        return 1;
    }
    else{
        return 0;
    }
}
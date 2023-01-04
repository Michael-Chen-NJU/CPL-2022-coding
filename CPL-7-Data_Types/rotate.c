//
// Created by HW on 2022/11/14.
//
#include <stdio.h>
#include <string.h>
int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    //get the numbers of each path
    int len;
    char path[1000];
        scanf("%s",path);
    len =  strlen (path);
//    for (int i = 0; i < len; ++i) {
//        printf("%c ",path[i]);
//    }



    //initialize x1,x2,y1,y2
    int x1 = 0, x2 = a, y1 = 0, y2 = b;

    //define what step to take in every path

    for (int i = 0; i < len; ++i) {
        if(path[i] == 'W'){
            if(x1 > x2){
                x1 = x1 - c - a;
            }
            else{
                x2 = x2 - c - a;
            }
            int temp1;
            temp1 = a;
            a = c;
            c = temp1;
        }
        if(path[i] == 'S'){
            if(x1 > x2){
                x2 = x2 + c + a;
            }
            else{
                x1 = x1 + c + a;
            }
            int temp2;
            temp2 = a;
            a = c;
            c = temp2;
        }
        if(path[i] == 'A'){
            if(y1 > y2){
                y1 = y1 - c - b;
            }
            else{
                y2 = y2 - c - b;
            }
            int temp3;
            temp3 = b;
            b = c;
            c = temp3;
        }
        if(path[i] == 'D'){
            if(y1 > y2){
                y2 = y2 + c + b;
            }
            else{
                y1 = y1 + c + b;
            }
            int temp4 ;
            temp4 = b;
            b = c;
            c = temp4;
        }
    }

    //sort out the ultimate x1,x2,y1,y2 according to the given path
    if(x1 > x2){
        printf("%d %d ", x2, x1);
    }
    else{
        printf("%d %d ", x1, x2);
    }
    if(y1 > y2){
        printf("%d %d ", y2, y1);
    }
    else{
        printf("%d %d ", y1, y2);
    }
}
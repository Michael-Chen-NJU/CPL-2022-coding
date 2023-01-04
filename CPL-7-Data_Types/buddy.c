//
// Created by HW on 2022/11/16.
//
#include <stdio.h>
#include <math.h>
int n, q;
int a[1000] = {0},b[1000] = {0};
int num = 1;
void divide(int x,int y);
int main(){

    scanf("%d%d",&n,&q);
    a[1] = pow(2,n);
    int id[1000] = {0},m[1000] = {0};
    char input[100] = {0};
    getchar();
    //main body

    for (int i = 0; i < q; ++i) {
        scanf("%c",&input[i]);
        //if the input was Q
        if(input[i] == 81){
            printf("%d\n",num);
            for (int j = 1; j <= num; ++j) {
                printf("%d ",b[j]);
            }
            printf("\n");
            getchar();
        }
        //if the input was A
        else if(input[i] == 65){
            scanf("%d %d",&id[i],&m[i]);
            getchar();
            divide(id[i],m[i]);
        }
    }
}


void divide(int x, int y){
    //use recursion to scan if there is proper a[k]
    int is_used = 0;
    int min = 0;

    for (int i = 0; i < 31; ++i) {
            if(pow(2,i) < y && pow(2,i+1) > y){
                y = pow(2,i+1);
                break;
            }else if( y == pow(2,i)){
                break;
            }
    }
    for (int j = 1; j <= num; ++j) {
        if(a[j] == y && b[j] == 0){
            b[j] = x;
            is_used = 1;
            break;
        }
    }
    if(is_used == 0){
        //if no proper a[k] was found divide
        //find the first not used min that is bigger than m[i]
        for (int j = 1; j <= num; ++j) {
            if(a[j] > y && b[j] == 0){
                min = j;
                break;
            }
        }
        //if min == num
        if(min == num){
            int temp;
            temp = a[min];
            a[min] = temp / 2;
            a[min + 1] = a[min];
        }
        //if min != num
        else{
            //move back the element behind min
            for (int i = num; i > min; --i) {
                a[i + 1] = a[i];
                b[i + 1] = b[i];
            }
            int temp;
            temp = a[min];
            a[min] = temp / 2;
            a[min + 1] = a[min];
        }
        //scan again
        num++;
        divide(x,y);
    }
}
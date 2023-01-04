//
// Created by HW on 2022/11/4.
//
#include <stdio.h>
//unsigned long long int C(int x, int y);
unsigned long long int Pascal(int a,int b);
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%llu",Pascal(b-1,a-1));
}
//unsigned long long int C(int x, int y){
//    unsigned long long int temp1=1, temp2=1;
//    for (long int i = 1; i <= x; ++i) {
//        temp1 = i * temp1;
//    }
//    if(x!=0){
//        for (long int i = y; i >= y - x + 1 ; --i) {
//            temp2=i*temp2;
//        }
//    }
//    return temp2/temp1;
//}
unsigned long long int Pascal(int a,int b){
    if(a == 0 ||(a == b)){
        return 1;
    }
    return Pascal(a-1,b-1)+Pascal(a,b-1);
}
//
// Created by HW on 2022/10/28.
//
#include <stdio.h>
#include <stdbool.h>
bool Is_Prime(int n);
int Reverse(int n);
int main()
{
    int n,new_i,count = 0;
    scanf("%d",&n);
    for (int i = 2; i <= n ; ++i) {
        if(Is_Prime(i)==true){
            if (Is_Prime(Reverse(i))==true){
                count ++;
            }
        }
    }
    printf("%d",count);
}
bool Is_Prime(int n){
    int divisor;

    if(n <= 1)
        return  false;
    for(divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0)
            return false;

    }
    return true;
}
int Reverse (int n){
    int a,b,c;

    if(n >=2 && n<10){
        return n;
    }
    if(n >=10 && n <100){
        a = n /10;
        b = n-(10 * a);
        return a + b * 10;
    }
    if(n >= 100 && n <1000){
        a = n /100;
        b = (n- (a * 100))/10;
        c = n - a * 100 -b * 10;
        return a + b * 10 +c * 100;
    }
}

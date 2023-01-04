//
// Created by HW on 2022/10/7.
//
#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a <= b){
        if(a<c){ printf("%d",a);}
        else{ printf("%d",c);}
    }else{ //a >=b
        if(b<c){ printf("%d",b);}
        else{ printf("%d",c);}
    }
    return 0;
}

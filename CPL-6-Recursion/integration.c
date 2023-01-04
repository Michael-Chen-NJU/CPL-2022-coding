//
// Created by HW on 2022/11/6.
//
#include <stdio.h>
#include <math.h>
double Simpson(double left,double right);
int a[30];
int n, p;
double f(int j,int k,double x);
double integration(double x,double y,double e);
int l, r;
int main(void){
    scanf("%d %d\n", &n, &p);
    for (int i = 0; i <= n; ++i) {
        scanf("%d ",&a[i]);
    }

    scanf("%d %d",&l,&r);
    //printf("%lf",f(n,p,r));
    printf("%f",integration( l,r , 15e-4));
}
double Simpson(double left,double right){
    double temp2;
    temp2 = (right+ left)/2.0;
    return (right - left)  * ((f(n,p,temp2) * 4.0)+ f(n,p,left)+ f(n,p,right)) / 6.0;
}
double f(int j,int k,double x){
    double sum = a[0];
    for (int i = 1; i <= j; ++i) {
        sum+= (pow(x,i)*a[i]);
    }
    return pow(sum,k);
}
double integration(double x, double y ,double e){
    double mid ;
    mid = (x  + y) / 2.0 ;
    double temp;
    double SL,SR,S;
    SL = Simpson(x,mid);
    SR = Simpson(mid,y);
    S = Simpson(x,y);
    temp = SL + SR - S;

    if(fabs(temp) <= e){
        return SL + SR +( temp / 15.0);
    }
    return integration(x,mid, e/2.0)+integration(mid,y,e/2.0);
}
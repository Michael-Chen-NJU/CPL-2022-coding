//
// Created by HW on 2022/11/15.
//
#include <stdio.h>
#include <stdbool.h>
int k;
int Va, Vb, Vc;
int a0, b0, c0;
int a1[10][100] = {0}, b1[10][100] = {0}, c1[10][100] = {0};
bool is_possible = 0;
//all the six possibilities
void AtoB(int a, int b, int c,int count);
void BtoA(int a, int b, int c,int count);
void AtoC(int a, int b, int c,int count);
void CtoA(int a, int b, int c,int count);
void BtoC(int a, int b, int c,int count);
void CtoB(int a ,int b, int c,int count);
int main(void){
    //get the input

    scanf("%d",&k);

    scanf("%d%d%d", &Va, &Vb, &Vc);
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    scanf("%d%d%d", &a0, &b0, &c0);
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 1; j < 7; ++j) {
            a1[j][i] = a, b1[j][i] = b, c1[j][i] = c;
        }
    }
    //try all the six possibilities

        AtoB(a,b,c,0);

        AtoC(a,b,c,0);

        BtoA(a,b,c,0);

        BtoC(a,b,c,0);

        CtoA(a,b,c,0);

        CtoB(a,b,c,0);

    if(is_possible == 1){
        printf("YES");
    }else{
        printf("NO");
    }
}

void AtoB(int a, int b, int c,int count){
    count++;
    if (a == a0 && b == b0 && c == c0) {
        is_possible = 1;
    }
    if(count > k){
        count--;
    }
    else {
        if (a + b <= Vb) {
            b1[1][count] = a + b;
            a1[1][count] = 0;
        } else {
            b1[1][count] = Vb;
            a1[1][count] = 0;
        }
        c1[1][count] = c;

        BtoC(a1[1][count], b1[1][count], c1[1][count],count);
        CtoB(a1[1][count], b1[1][count], c1[1][count],count);
        CtoA(a1[1][count], b1[1][count], c1[1][count],count);
    }
}
void BtoA(int a, int b, int c,int count){
    count++;
    if (a == a0 && b == b0 && c == c0) {
        is_possible = 1;
    }
    if(count > k){
        count--;
    }else {
        if (a + b <= Va) {
            a1[2][count] = a + b;
            b1[2][count] = 0;
        } else {
            a1[2][count] = Va;
            b1[2][count] = 0;
        }
        c1[2][count] = c;

        AtoC(a1[2][count], b1[2][count], c1[2][count],count);
        CtoA(a1[2][count], b1[2][count], c1[2][count],count);
        CtoB(a1[2][count], b1[2][count], c1[2][count],count);
    }
}
void AtoC(int a, int b, int c,int count){
    count++;
    if (a == a0 && b == b0 && c == c0) {
        is_possible = 1;
    }
    if(count > k){
        count --;
    }else{
        if (a + c <= Vc) {
            a1[3][count] = 0;
            c1[3][count] = a + c;
        } else {
            a1[3][count] = 0;
            c1[3][count] = Vc;
        }
        b1[3][count] = b;

        BtoC(a1[3][count], b1[3][count], c1[3][count],count);
        CtoB(a1[3][count], b1[3][count], c1[3][count],count);
        BtoA(a1[3][count], b1[3][count], c1[3][count],count);
    }
}
void CtoA(int a,int b, int c,int count){
    count++;
    if (a == a0 && b == b0 && c == c0) {
        is_possible = 1;
    }
    if(count > k){
        count --;
    }else {
        if (a + c <= Va) {
            a1[4][count] = a + c;
            c1[4][count] = 0;
        } else {
            a1[4][count] = Va;
            c1[4][count] = 0;
        }
        b1[4][count] = b;
        AtoB(a1[4][count], b1[4][count], c1[4][count],count);
        BtoA(a1[4][count], b1[4][count], c1[4][count],count);
        BtoC(a1[4][count], b1[4][count], c1[4][count],count);
    }
}
void BtoC(int a,int b, int c,int count){
    count++;
    if (a == a0 && b == b0 && c == c0) {
        is_possible = 1;
    }
    if(count > k){
        count --;
    }else {
        if (b + c <= Vc) {
            c1[5][count] = b + c;
            b1[5][count] = 0;
        } else {
            c1[5][count] = Vc;
            b1[5][count] = 0;
        }
        a1[5][count] = a;

        AtoB(a1[5][count], b1[5][count], c1[5][count],count);
        CtoA(a1[5][count], b1[5][count], c1[5][count],count);
        AtoC(a1[5][count], b1[5][count], c1[5][count],count);
    }
}
void CtoB(int a,int b ,int c,int count){
    count++;
    if (a == a0 && b == b0 && c == c0) {
        is_possible = 1;
    }
    if(count > k){
        count --;
    }else{
        if (b + c <= Vb) {
            b1[6][count] = b + c;
            c1[6][count] = 0;
        } else {
            b1[6][count] = Vb;
            c1[6][count] = 0;
        }
        a1[6][count] = a;

        AtoB(a1[6][count], b1[6][count], c1[6][count],count);
        BtoA(a1[6][count], b1[6][count], c1[6][count],count);
        AtoC(a1[6][count], b1[6][count], c1[6][count],count);
    }
}


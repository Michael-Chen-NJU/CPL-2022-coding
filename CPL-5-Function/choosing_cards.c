//
// Created by HW on 2022/10/31.
//
#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>

#define TYPES 4
#define NUM 13
int main(void){
    bool in_hand[TYPES][NUM]={0};

    const int card_num[]={2,3,4,5,6,7,8,9,10,74,81,75,65};
    char card_type1[100]="梅花";
    char card_type2[100]="方片";
    char card_type3[100]="红桃";
    char card_type4[100]="黑桃";
    for (int i = 0; i < 13; ++i) {
        printf("%s%d",card_type1,card_num[i]);
        printf("%s%d",card_type2,card_num[i]);
        printf("%s%d",card_type3,card_num[i]);
        printf("%s%d",card_type4,card_num[i]);
    }
}
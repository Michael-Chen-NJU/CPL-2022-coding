//
// Created by HW on 2022/12/10.
//
#include <stdio.h>
int plus[10005] = {0};
int subtract[10005] = {0};
int multi[20010] = {0};
void PLUS();
void SUBSTRACT();
void MULTI();
char variable[15] = {0};
int big_index = 0;
int index_plus = 0;
int main(){
    int index_1, index_2;
    scanf("%d %d",&index_1,&index_2);


    scanf("%s",variable);

    int factor_1[10005] = {0};
    int factor_2[10005] = {0};
    for (int i = index_1; i >= 0; --i) {
        scanf("%d",&factor_1[i]);
    }
    for (int i = index_2; i >= 0; --i) {
        scanf("%d",&factor_2[i]);
    }

    if(index_2 >= index_1) {
        big_index = index_2;
    }else{
        big_index = index_1;
    }

    index_plus = index_2 + index_1;
//先把0到可能最高项的结果得出来

    for (int i = big_index; i >= 0; --i) {
        plus[i] = factor_1[i] + factor_2[i];
    }


    for (int i = big_index; i >= 0; --i) {
        subtract[i] = factor_1[i] - factor_2[i];
    }

    for (int i = index_2 + index_1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            multi[i] += factor_1[j] * factor_2[i - j];
        }
        //如何确定一项的系数？
        //P1中0次项和P2中i次项 + P1中1次项和P2中i-1次项 直到P1中i次项和P2中0次项
    }
    PLUS();
    printf("\n");

    //减法环节
    SUBSTRACT();
    printf("\n");
    //乘法环节
    MULTI();
    printf("\n");
}
//除最高次项外，若项的系数为负数，则不输出前面的 +
//除常数项外，系数为零的项不输出，系数为 ±1 的项不输出 1
//使用 n^p 表示 n 的 p 次方（p>1），p 为 1 时只输出 n，p 为 0 时只输出系数
void PLUS(){
//判断最高项是哪一项
int is_zero = 0;
int max = 0;
for (int i = big_index; i > 0; --i) {
if(plus[i] != 0){
is_zero = 1;
max = i;
break;
}
}
for (int i = max; i > 0; --i) {
//分类讨论 可能还有漏情况的
//找到系数非0的最高次项
//有关最高次项的
    if(i == max) {
        if (plus[i] != 0 && plus[i] != 1 && plus[i] != -1) {
            printf("%d%s^%d", plus[i], variable, i);
        } else if (plus[i] == 1) {
            printf("%s^%d", variable, i);
        }else if(plus[i] == -1){
            printf("-%s^%d",variable,i);
        }
    }
//有关中间项数的 且不为i== 1
    else if(i != 1 && i < max) {
        if (plus[i] > 0 && plus[i] != 1 ) {
            printf("+%d%s^%d", plus[i], variable, i);
        } else if (plus[i] < 0 && plus[i] != -1) {
            printf("%d%s^%d", plus[i], variable, i);
        }else if(plus[i] == 0){

        }else if (plus[i] == -1) {
            printf("-%s^%d", variable, i);
        }else if (plus[i] == 1) {
            printf("+%s^%d", variable, i);
        }
    }
//如果i == 1且不是最高次
    else if(i == 1&& i < max){
            if(plus[i] > 0 && plus[i] != 1) {
                printf("+%d%s",plus[i],variable);
            }else if(plus[i] == 1) {
                printf("+%s",variable);
            }else if(plus[i] < 0 && plus[i] != -1){
                printf("%d%s",plus[i],variable);
            }else if(plus[i] == -1){
                printf("-%s",variable);
            }
        }
    }
//定义一个变量用来确定前面是否全部为0
//如果全是0 则最后一个如果是0 则要输出0 则最后一个如果是正数 不用输出+ 如果是负数需输出-
//如果不全为0 则最后一个如果是0 不输出 最后一个是正数 要输出+ 如果是负数要输出-
    if(is_zero == 0){
        printf("%d",plus[0]);
    }
    else{
        if(plus[0] > 0){
            printf("+%d",plus[0]);
        }else if(plus[0] < 0){
            printf("%d",plus[0]);
        }
        }
}

void SUBSTRACT(){
    int is_zero = 0;
    int max = 0;
    for (int i = big_index; i > 0; --i) {
        if(subtract[i] != 0){
            is_zero = 1;
            max = i;
            break;
        }
    }
    for (int i = max; i > 0; --i) {

        //分类讨论 可能还有漏情况的
        //有关最高次项的
        if(i == max) {
            if (subtract[i] != 0 && subtract[i] != 1 && subtract[i] != -1) {
                printf("%d%s^%d", subtract[i], variable, i);
            } else if (subtract[i] == 1) {
                printf("%s^%d", variable, i);
            }else if(subtract[i] == -1){
                printf("-%s^%d",variable,i);
            }
        }

            //有关中间项数的 且不为i== 1
        else if(i != 1 && i < max) {
            if (subtract[i] == 1) {
                printf("+%s^%d", variable, i);
            } else if (subtract[i] > 0 && subtract[i] != 1 ) {
                printf("+%d%s^%d", subtract[i], variable, i);
            } else if (subtract[i] < 0 && subtract[i] != -1) {
                printf("%d%s^%d", subtract[i], variable, i);
            }else if(subtract[i] == 0){

            }else if (subtract[i] == -1) {
                printf("-%s^%d", variable, i);
            }
        }

            //如果i == 1且不是最高次项
        else if(i == 1&& i < max){
            if(subtract[i] > 0 && subtract[i] != 1) {
                printf("+%d%s",subtract[i],variable);
            }else if(subtract[i] == 1) {
                printf("+%s",variable);
            }else if(subtract[i] < 0 && subtract[i] != -1){
                printf("%d%s",subtract[i],variable);
            }else if(subtract[i] == -1){
                printf("-%s",variable);
            }
        }

    }

    //定义一个变量用来确定前面是否全部为0
    //如果全是0 则最后一个如果是0 则要输出0 则最后一个如果是正数 不用输出+ 如果是负数需输出-
    //如果不全为0 则最后一个如果是0 不输出 最后一个是正数 要输出+ 如果是负数要输出-
    if(is_zero == 0){
        printf("%d",subtract[0]);
    }else{
        if(subtract[0] > 0){
            printf("+%d",subtract[0]);
        }else if(subtract[0] < 0){
            printf("%d",subtract[0]);
        }
    }
}
void MULTI(){
    int is_zero = 0;
    int max = 0;
    for (int i = index_plus; i > 0; --i) {
        if(multi[i] != 0){
            is_zero = 1;
            max = i;
            break;
        }
    }

    for (int i = max; i > 0; --i) {
        //有关最高次项的
        if (i == max) {
            if (multi[i] != 0 && multi[i] != 1 && multi[i] != -1) {
                printf("%d%s^%d", multi[i], variable, i);
            } else if (multi[i] == 1) {
                printf("%s^%d", variable, i);
            } else if (multi[i] == -1) {
                printf("-%s^%d", variable, i);
            }
        }

            //有关中间项数的 且不为i== 1
        else if (i != 1 && i < max) {
            if (multi[i] == 1) {
                printf("+%s^%d", variable, i);
            } else if (multi[i] > 0 && multi[i] != 1) {
                printf("+%d%s^%d", multi[i], variable, i);
            } else if (multi[i] < 0 && multi[i] != -1) {
                printf("%d%s^%d", multi[i], variable, i);
            } else if (multi[i] == 0) {

            } else if (multi[i] == -1) {
                printf("-%s^%d", variable, i);
            }
        }

            //如果i == 1且不是最高次项
        else if (i == 1&& i < max) {
            if (multi[i] > 0 && multi[i] != 1) {
                printf("+%d%s", multi[i], variable);
            } else if (multi[i] == 1) {
                printf("+%s", variable);
            } else if (multi[i] < 0 && multi[i] != -1) {
                printf("%d%s", multi[i], variable);
            } else if (multi[i] == -1) {
                printf("-%s", variable);
            }
        }
    }

    //定义一个变量用来确定前面是否全部为0
    //如果全是0 则最后一个如果是0 则要输出0 则最后一个如果是正数 不用输出+ 如果是负数需输出-
    //如果不全为0 则最后一个如果是0 不输出 最后一个是正数 要输出+ 如果是负数要输出-
    if(is_zero == 0){
        printf("%d",multi[0]);
    }else{
        if(multi[0] > 0){
            printf("+%d",multi[0]);
        }else if(multi[0] < 0){
            printf("%d",multi[0]);
        }
    }

}
//
// Created by HW on 2022/11/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //将不用子参数的参数存入option_1，将需要子参数的参数存入option_2
    char *option = (char *) malloc(sizeof (char) * 150);
    char *option_1 = (char *) malloc(sizeof (char) * 150);
    char *option_2 = (char *) malloc(sizeof (char) * 150);

    //置零
    memset(option,0,150);
    memset(option_1,0,150);
    memset(option_2,0,150);

    scanf("%s",&(*option));
    int len_option = strlen(option);
    //将参数分类
    int type_1 = 0, type_2 = 0;
    for (int i = 0; i < len_option; ++i) {
        //第一种参数，即无子参数的参数
        if(*(option + i) != ':' && *(option + i + 1) != ':'){
            *(option_1 + type_1) = *(option + i);
            ++type_1;
        }
        //第二种参数，有子参数的参数
        else if(*(option + i) != ':' && *(option + i + 1) == ':'){
            *(option_2 + type_2) = *(option + i);
            ++type_2;
        }
    }
    getchar();
    char *name = (char *) malloc(sizeof(char) * 1050);
    scanf("%s",&(*name));
    char *order = (char *) malloc(sizeof (char) * 1050);
    char *print = (char *) malloc(sizeof (char) * 1050);
    char *sub_order = (char *) malloc(sizeof (char) * 1050);
    char *origin_sub_order = sub_order;
    int *sub_len = (int *) malloc(sizeof (int) * 1050);
    int *is_option = (int *) malloc(sizeof (int) * 1050);
    memset(is_option,0,sizeof (int) * 1050);
    int count = 0;
    for (int m = 0; m < 1024; ++m) {
        int input;
        input = scanf("%s",&(*order));
        int len_order = strlen(order);
      if(input == EOF){
            break;
        }else{
            if(* order =='-'){

                //检查是否是第一种参数，即无子参数的参数
                for (int i = 0; i < type_1; ++i) {
                    if(*(order + 1) == *(option_1 + i)){
                        *(is_option + count) = 1;
                        *(print + count) = *(order + 1);
                        break;
                    }
                }
                //如果是第一种参数则无需检查是否是第二种参数，如果不是则继续检查
                if(*(is_option + count) == 0){
                    for (int i = 0; i < type_2; ++i) {
                        if(*(order + 1) == *(option_2 + i)) {
                            *(is_option + count) = 2;
                            *(print + count) = *(order + 1);
                            order += 2;
                            //如果没有子参数的特殊情况
                            if(scanf("%s",&(*order)) == EOF){
                                printf("%s: option requires an argument -- '%c'",name,*(order - 1));
                                exit(0);
                            }else{
                                * (sub_len + count) = strlen(order);
                                for (int j = 0; j < * (sub_len + count); ++j) {
                                    *(sub_order + j) = *(order);
                                    ++order;
                                }
                                sub_order += * (sub_len + count);
                            }
                            break;
                        }
                    }
                }
                //如果两种变量都不是，则直接返回报错
                if(*(is_option + count) == 0){
                    printf("%s: invalid option -- '%c'",name,*(order + 1));
                    exit(0);
                }
                ++count;
            }
        }
        order += len_order;
    }
    sub_order = origin_sub_order;
    printf("%s\n",name);
    for (int i = 0; i < count; ++i) {
        if(*(is_option + i) == 1) {
            printf("%c\n", *(print + i));
        }
        else if(*(is_option + i) == 2){
            printf("%c=",*(print + i));
            for (int j = 0; j < *(sub_len + i); ++j) {
                printf("%c",*(sub_order + j));
            }
            sub_order += *(sub_len + i);
            printf("\n");
        }
    }
}
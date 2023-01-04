//
// Created by HW on 2022/11/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int match_reserved(char *a);
int match_integer(char *a);
int match_float(char *a);
int match_operator(char *a);
int match_variable(char *a);
int main()
{
    char *s = (char *) malloc(sizeof (char) * 4100);
    char *print = (char *) malloc(sizeof (char) * 4100);
    int *len_print = (int *)malloc(sizeof (int) * 4100);
    char *origin_p = print;
    int count = 0;
    while (scanf("%s", &(*s)) != EOF) {
    //for (int i = 0; i < 22; ++i) {
        //scanf("%s", &(*s));
        char *position = strchr(s, ';');
        int len_code = strlen(s);
        count++;
        
        if (position == NULL) {
            int outcome1;
            outcome1 = match_reserved(s);
            if (outcome1 == 1) {
                *(print) = 'r';*(print + 1) = 'e';*(print + 2) = 's';*(print + 3) = 'e'; *(print + 4) = 'r';
                *(print + 5) = 'v';*(print + 6) = 'e';*(print + 7) = 'd';
                *(len_print + count) = 8;
                print += 8;
            } else {
                int outcome2;
                outcome2 = match_integer(s);
                if (outcome2 == 1) {
                    *(print ) = 'i';*(print + 1) = 'n';*(print + 2) = 't';*(print + 3) = 'e'; *(print + 4) = 'g';
                    *(print + 5) = 'e';*(print + 6) = 'r';
                    *(len_print + count) = 7;
                    print += 7;
                } else if (outcome2 == -1) {
                    printf("Compile Error");
                    exit(0);
                } else {
                    int outcome3;
                    outcome3 = match_float(s);
                    if (outcome3 == 1) {
                        *(print ) = 'f';*(print + 1) = 'l';*(print + 2) = 'o';*(print + 3) = 'a'; *(print + 4) = 't';
                        *(len_print + count) = 5;
                        print += 5;
                    } else if (outcome3 == -1) {
                        printf("Compile Error");
                        exit(0);
                    } else{
                        int outcome4;
                        outcome4 = match_operator(s);
                        if (outcome4 == 1) {
                            *(print) = 'o';*(print + 1) = 'p';*(print + 2) = 'e';*(print + 3) = 'r'; *(print + 4) = 'a';
                            *(print + 5) = 't';*(print + 6) = 'o';*(print + 7) = 'r';
                            *(len_print + count) = 8;
                            print += 8;
                        } else if (outcome4 == -1) {
                            printf("Compile Error");
                            exit(0);
                        } else{
                            int outcome5;
                            outcome5 = match_variable(s);
                            if (outcome5 == 1) {
                                *(print ) = 'v';*(print + 1) = 'a';*(print + 2) = 'r';*(print + 3) = 'i'; *(print + 4) = 'a';
                                *(print + 5) = 'b';*(print + 6) = 'l';*(print + 7) = 'e';
                                *(len_print + count) = 8;
                                print += 8;
                            } else if (outcome5 == -1) {
                                printf("Compile Error");
                                exit(0);
                            }
                        }

                    }

                }

            }
            s += len_code;
        }
        //如果含有；
        else{
            if(*s == ';'){
                *print = '\n';
                *(len_print + count) = 1;
                ++print;
                continue;
            }
            else {
                char *s1 = (char *) malloc(sizeof(char) * 4100);
                char *s2 = (char *) malloc(sizeof(char) * 4100);
                //将s分成s1和s2
                for (int j = 0; j < 4096; ++j) {
                    *(s1 + j) = *(s + j);
                    if (s + j == position - 1) {
                        *(s1 + j + 1) = '\0';
                        break;
                    }
                }

                int outcome1;
                outcome1 = match_reserved(s1);
                if (outcome1 == 1) {
                    *(print) = 'r';
                    *(print + 1) = 'e';
                    *(print + 2) = 's';
                    *(print + 3) = 'e';
                    *(print + 4) = 'r';
                    *(print + 5) = 'v';
                    *(print + 6) = 'e';
                    *(print + 7) = 'd';
                    *(print + 8) = '\n';
                    *(len_print + count) = 9;
                    print += 9;
                } else {
                    int outcome2;
                    outcome2 = match_integer(s1);
                    if (outcome2 == 1) {
                        *(print) = 'i';
                        *(print + 1) = 'n';
                        *(print + 2) = 't';
                        *(print + 3) = 'e';
                        *(print + 4) = 'g';
                        *(print + 5) = 'e';
                        *(print + 6) = 'r';
                        *(print + 7) = '\n';
                        *(len_print + count) = 8;
                        print += 8;
                    } else if (outcome2 == -1) {
                        printf("Compile Error");
                        exit(0);
                    } else {
                        int outcome3;
                        outcome3 = match_float(s1);
                        if (outcome3 == 1) {
                            *(print) = 'f';
                            *(print + 1) = 'l';
                            *(print + 2) = 'o';
                            *(print + 3) = 'a';
                            *(print + 4) = 't';
                            *(print + 5) = '\n';
                            *(len_print + count) = 6;
                            print += 6;
                        } else if (outcome3 == -1) {
                            printf("Compile Error");
                            exit(0);
                        } else {
                            int outcome4;
                            outcome4 = match_operator(s1);
                            if (outcome4 == 1) {
                                *(print) = 'o';
                                *(print + 1) = 'p';
                                *(print + 2) = 'e';
                                *(print + 3) = 'r';
                                *(print + 4) = 'a';
                                *(print + 5) = 't';
                                *(print + 6) = 'o';
                                *(print + 7) = 'r';
                                *(print + 8) = '\n';
                                *(len_print + count) = 9;
                                print += 9;
                            } else if (outcome4 == -1) {
                                printf("Compile Error");
                                exit(0);
                            } else {
                                int outcome5;
                                outcome5 = match_variable(s1);
                                if (outcome5 == 1) {
                                    *(print) = 'v';
                                    *(print + 1) = 'a';
                                    *(print + 2) = 'r';
                                    *(print + 3) = 'i';
                                    *(print + 4) = 'a';
                                    *(print + 5) = 'b';
                                    *(print + 6) = 'l';
                                    *(print + 7) = 'e';
                                    *(print + 8) = '\n';
                                    *(len_print + count) = 9;
                                    print += 9;
                                } else if (outcome5 == -1) {
                                    printf("Compile Error");
                                    exit(0);
                                }
                            }

                        }

                    }

                }
                //对s2检查操作
                char *scan = position + 1;
                if (*scan != '\0') {
                    for (int j = 1; j < 4096; ++j) {
                        *(s2 + j - 1) = *(position + j);
                        if (position + j == s + len_code) {
                            *(s2 + j) = '\0';
                            break;
                        }
                    }
                    int outcome_1;
                    outcome_1 = match_reserved(s2);
                    if (outcome_1 == 1) {
                        *(print) = 'r';
                        *(print + 1) = 'e';
                        *(print + 2) = 's';
                        *(print + 3) = 'e';
                        *(print + 4) = 'r';
                        *(print + 5) = 'v';
                        *(print + 6) = 'e';
                        *(print + 7) = 'd';
                        *(len_print + count) += 8;
                        print += 8;
                    } else {
                        int outcome_2;
                        outcome_2 = match_integer(s2);
                        if (outcome_2 == 1) {
                            *(print) = 'i';
                            *(print + 1) = 'n';
                            *(print + 2) = 't';
                            *(print + 3) = 'e';
                            *(print + 4) = 'g';
                            *(print + 5) = 'e';
                            *(print + 6) = 'r';
                            *(len_print + count) += 7;
                            print += 7;
                        } else if (outcome_2 == -1) {
                            printf("Compile Error");
                            exit(0);
                        } else {
                            int outcome_3;
                            outcome_3 = match_float(s2);
                            if (outcome_3 == 1) {
                                *(print) = 'f';
                                *(print + 1) = 'l';
                                *(print + 2) = 'o';
                                *(print + 3) = 'a';
                                *(print + 4) = 't';
                                *(len_print + count) += 5;
                                print += 5;
                            } else if (outcome_3 == -1) {
                                printf("Compile Error");
                                exit(0);
                            } else {
                                int outcome_4;
                                outcome_4 = match_operator(s2);
                                if (outcome_4 == 1) {
                                    *(print) = 'o';
                                    *(print + 1) = 'p';
                                    *(print + 2) = 'e';
                                    *(print + 3) = 'r';
                                    *(print + 4) = 'a';
                                    *(print + 5) = 't';
                                    *(print + 6) = 'o';
                                    *(print + 7) = 'r';
                                    *(len_print + count) += 8;
                                    print += 8;
                                } else if (outcome_4 == -1) {
                                    printf("Compile Error");
                                    exit(0);
                                } else {
                                    int outcome_5;
                                    outcome_5 = match_variable(s2);
                                    if (outcome_5 == 1) {
                                        *(print) = 'v';
                                        *(print + 1) = 'a';
                                        *(print + 2) = 'r';
                                        *(print + 3) = 'i';
                                        *(print + 4) = 'a';
                                        *(print + 5) = 'b';
                                        *(print + 6) = 'l';
                                        *(print + 7) = 'e';
                                        *(len_print + count) += 8;
                                        print += 8;
                                    } else if (outcome_5 == -1) {
                                        printf("Compile Error");
                                        exit(0);
                                    }
                                }

                            }

                        }

                    }
                }
            }
        }
    }
    
    //打印
    for (int k = 1; k <= count; ++k) {
        for (int l = 0; l < *(len_print + k); ++l) {
            printf("%c",*(origin_p + l));
        }
        origin_p +=*(len_print + k);
        if(*(origin_p - 1) != '\n') {
            printf(" ");
        }
    }
//    char *x = "a2a";
//    if(match_variable(x) == 1){
//        printf("variable");
//    }else if(match_variable(x) == 0){
//        printf("not variable");
//    }else if(match_variable(x) == -1){
//        printf("Compile error");
//    }
}
//函数作用：匹配是否属于reserved
int match_reserved(char *a){
    if(strcmp(a,"const") == 0 || strcmp(a,"int") == 0 || strcmp(a,"float") == 0 ||strcmp(a,"double") == 0
    ||strcmp(a,"long") == 0 || strcmp(a,"static") == 0 || strcmp(a,"void") == 0 || strcmp(a,"char") == 0
    ||strcmp(a,"extern") == 0 || strcmp(a,"return") == 0 || strcmp(a,"break") == 0 || strcmp(a,"enum") == 0
    ||strcmp(a,"struct") == 0 || strcmp(a,"typedef") == 0 || strcmp(a,"union") == 0 || strcmp(a,"goto") == 0)
    {
        return 1;
    }else{
        return 0;
    }
}

//函数作用：匹配是否属于integer
//并且保证了如果输入仅仅为'-’时判断为不是integer
//如果为int 返回1
//如果不是int 返回0
//如果在多个输入时出现 - 返回-1
int match_integer(char *a){
    int len_int = strlen(a);
    if(len_int > 1) {
        for (int j = 0; j < len_int; ++j) {
            if (*(a + j) >= '0' && *(a + j) <= '9') {
                continue;
            } else if (*(a + j) == '-') {
                return -1;
            } else {
                return 0;
            }
        }
        return 1;
    }else{
        if (*(a) >= '0' && *(a) <= '9'){
            return 1;
        }else{
            return 0;
        }
    }
}

//匹配是否为浮点数
//如果仅有一个. 并且符合要求 返回1
//如果出现两个. 或者在多个输入时出现 - 返回-1
//如果不是float 返回0
int match_float(char *a){
    int len_float = strlen(a);
    if(len_float > 1){
        int count_float = 0;
        for (int j = 0; j < len_float; ++j) {
            if(*(a + j) == '.'){
                ++count_float;
            }else if(*(a + j) >= '0' && *(a + j) <= '9'){
                continue;
            }else if(*(a + j) == '-'){
                return -1;
            }
        }
        if(count_float == 1){
            return 1;
        }else if(count_float > 1){
            return -1;
        }else{
            return 0;
        }
    }else{
        if (*(a) == '.'){
            return -1;
        }else{
            return 0;
        }
    }
}
//判断是否为运算符
//如果属于所给的11种运算符 则返回1
//如果是1.数字 或者2.字母 或者3.存在. 或者4._ 或者5.- 则不是运算符 返回0
//如果既不是数字也不是字母 则说明为不和约定成分 返回-1
int match_operator(char *a){
    int len_operator = strlen(a);
    if(len_operator == 1){
        if(*a == '+' || *a == '-' || *a == '*' || *a == '/' || *a == '=' || *a == '<' || *a == '>'){
            return 1;
        }else if((*a >= '0' && *a <= '9') || (*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z')
        || *a == '.' || *a == '_')
        {
            return 0;
        }else{
            return -1;
        }
    }else if(len_operator == 2){
        if((*a == '=' && *(a + 1) == '=') || (*a == '!' && *(a + 1) == '=') || (*a == '<' && *(a + 1) =='=')
        ||(*a == '>' && *(a + 1) == '=')){
            return 1;
        }else if((*a >= '0' && *a <= '9') || (*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z' )
        || *a == '.' || *a =='_' || *a == '-'){
            if((*(a + 1) >= '0' && *(a + 1) <= '9') || (*(a + 1) >= 'a' && *(a + 1) <= 'z')
            || (*(a + 1) >= 'A' && *(a + 1) <= 'Z') || *(a + 1) == '.'|| *(a + 1) == '_' || *(a + 1) == '-'){
                return 0;
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }else{
        for (int j = 0; j < len_operator; ++j) {
            if((*(a + j) >= '0' && *(a + j) <= '9') || (*(a + j) >= 'a' && *(a + j) <= 'z')
            || (*(a + j) >= 'A' && *(a + j) <= 'Z') ||*(a +j) == '.' || *(a + j) == '_' || *(a + j) == '-'){
                continue;
            }else{
                return -1;
            }
        }
        return 0;
    }
}
//判断是否为变量
int match_variable(char *a){
    int len_variable = strlen(a);
    if(*a >= '0' && *a <= '9'){
        return -1;
    }else{
        for (int j = 0; j < len_variable; ++j) {
            if((*(a + j) >= '0' && *(a + j) <= '9') || (*(a + j) >= 'a' && *(a + j) <= 'z')
               || (*(a + j) >= 'A' && *(a + j) <= 'Z') || *(a + j) == '_')
            {
                continue;
            }else{
                return 0;
            }
        }
        if(match_reserved(a) == 1){
            return 0;
        }else {
            return 1;
        }
    }
}
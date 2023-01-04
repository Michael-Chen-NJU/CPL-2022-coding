//
// Created by HW on 2022/11/18.
//
#include <stdio.h>
#include <string.h>
int judge(unsigned int a);
char brackets[1000] = {0};
int main(void){
    int T;
    scanf("%d",&T);

    //main body
    for (int i = 0; i < T; ++i) {
        scanf("%s",brackets);

        unsigned int len = strlen(brackets);
        judge(len);
        if(judge(len) == 0){
            printf("True\n");
        }else{
            printf("False\n");
        }
        //reset the array
        memset(brackets,0,sizeof(brackets));
    }
}
int judge(unsigned int a){
    char stack[1000] = {0};
    int num = 0;
    for(int i = 0; i < a; ++i){
        //push stack
        if(brackets[i] == '{' || brackets[i] == '(' || brackets[i] == '['){
            stack[num] = brackets[i];
            num ++;
        }

        //scan the top and pop
        else if(brackets[i] == '}'){
                if(stack[num - 1] == '{'){
                    stack[num - 1] = 0;
                    num --;
                }
            }

        else if(brackets[i] == ']'){

            if(stack[num - 1] == '['){
                stack[num - 1] = 0;
                num --;
            }
        }

        else if(brackets[i] == ')'){
            if(stack[num - 1] == '('){
                stack[num - 1] = 0;
                num --;
            }
        }
    }

    //judge if the brackets were right
    if(num ==0){
        return 0;
    }
    //judge if they were wrong
    else {
        return 1;
    }
}
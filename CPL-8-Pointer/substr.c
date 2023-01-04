//
// Created by HW on 2022/11/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char *first_element = (char *) malloc(sizeof(char));
    gets(first_element);
    char *substr = (char *)malloc(sizeof (char));
    gets(substr);

    for (int i = 0; i <= strlen(first_element) - strlen(substr); ++i) {
        for (int j = 0, k = i; j <= strlen(substr) && *(substr + j) == *(first_element + k); ++j,++k) {
            if(j == strlen(substr) - 1){
                printf("%d ",i);
            }
        }
    }
    free(substr);
    free(first_element);
}
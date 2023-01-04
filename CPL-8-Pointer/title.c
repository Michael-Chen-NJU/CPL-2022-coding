#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
        for (int j = 0; j < 4096; ++j) {
            char *title = (char *) malloc(sizeof(char) * 4096);
            int a;
            a = scanf("%s",&(*title));
            //printf("%s",(title));
            if(a == EOF){
                break;
            }
            if(*title <= 'z' && *title >= 'a'){
                *title -= 32;
            }
            for (int i = 1; i < strlen(title); ++i) {
                if(*(title + i) >= 'A' && *(title + i) <= 'Z'){
                    *(title + i) += 32;
                }
            }
            printf("%s ",title);
            free(title);
        }
    }
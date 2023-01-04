//
// Created by HW on 2022/12/10.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    typedef struct information{
        char *name;
        int attack;
        int defense;
        int organize;
    }NAME;
    int num = 0;
    scanf("%d",&num);
    getchar();
    char *team_name [1000]= {NULL,NULL};
    double score[1000][3]= {0};
    int score_bool[1000][3] = {0};
    int Attack[1000] = {0};
    int Defense[1000] = {0};
    int Organize[1000] = {0};
    for (int i = 0; i < num; ++i) {
        team_name[i] = (char *)malloc(sizeof (char) * 1000);
        scanf("%s",&(*team_name[i]));
        getchar();
        //printf("%s",team_name[i]);
        for (int j = 0; j < 11; ++j) {
            int attack,defense,organize;
            char *name = (char *) malloc(sizeof (char) *100);
            scanf("%s",&(*name));
            scanf("%d",&(attack));
            scanf("%d",&(defense));
            scanf("%d",&(organize));
            getchar();
            Attack[i] += attack;
            Defense[i] += defense;
            Organize[i] += organize;
        }
        score[i][0] = (double) Attack[i] / 11;
        score[i][1] = (double) Defense[i] / 11;
        score[i][2] = (double) Organize[i] / 11;
    }

    //先排进攻的
    for (int i = 0; i < num; ++i) {
        int index = 0;
        double max;
        for (int j = 0; j < num; ++j) {
            if(score_bool[j][0] == 0){
                index = j;
                max = score[j][0];
                break;
            }
        }
        for (int j = 0; j < num; ++j) {
            if(score[j][0] > max && score_bool[j][0] == 0){
                index = j;
                max = score[j][0];
            }
        }
        score_bool[index][0] = 1;
        printf("%s ", team_name[index]);
    }
    printf("\n");

    for (int i = 0; i < num; ++i) {
        int index = 0;
        double max;
        for (int j = 0; j < num; ++j) {
            if(score_bool[j][1] == 0){
                index = j;
                max = score[j][1];
                break;
            }
        }
        for (int j = 0; j < num; ++j) {
            if(score[j][1] > max && score_bool[j][1] == 0){
                index = j;
                max = score[j][1];
            }
        }
        score_bool[index][1] = 1;
        printf("%s ", team_name[index]);
    }
    printf("\n");
    for (int i = 0; i < num; ++i) {
        int index = 0;
        double max;
        for (int j = 0; j < num; ++j) {
            if(score_bool[j][2] == 0){
                index = j;
                max = score[j][2];
                break;
            }
        }
        for (int j = 0; j < num; ++j) {
            if(score[j][2] > max && score_bool[j][2] == 0){
                index = j;
                max = score[j][2];
            }
        }
        score_bool[index][2] = 1;
        printf("%s ", team_name[index]);
    }
    printf("\n");
}
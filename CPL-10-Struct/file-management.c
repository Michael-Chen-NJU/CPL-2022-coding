//
// Created by HW on 2022/12/11.
//
#include <stdio.h>
#include <string.h>
//记得改变数字为10005
//level用来表示它的坐标
int level_x[100] = {0};
int level_y[100] = {0};
int count[100] = {0};
//sub_relation用来表示它的子文件数
int sub_relation_num[100][100] = {0};
int sub_relation[100][100] = {0};

void wrap(int x,int j);

int main(){
    int file_num = 0, order_num = 0;
    scanf("%d %d",&file_num,&order_num);
    getchar();

    //按照1到file_num对name进行存储标号
    char file_name[100][15] = {0};
    //它所属的母文件
    char sub_file[100][15] = {0};

    //按照1到order_num对quest进行存储标号
    char que_name[100][15] = {0};
    char remove_name[100][15] = {0};
    //其参数存储在order中
    char order[100][15] = {0};

    //将文件以其归属存进数组
    for (int i = 1; i <= file_num; ++i) {
        scanf("%s",&(*(file_name[i])));
        scanf("%s",&(*(sub_file[i])));
        for (int j = 1; j <= i; ++j) {
            if(strcmp((sub_file[i]),"~~~") == 0){
                count[file_num] ++;
                level_x[i] = file_num;
                level_y[i] = count[file_num];
                sub_relation_num[(level_x[i])][(level_y[i])] ++;
            }else if(strcmp((sub_file[i]),file_name[i - j]) == 0){
                level_x[i] = level_x[i - j] - 1;
                count[(level_x[i])] ++;
                level_y[i] = count[(level_x[i])];
                int x = level_x[i]; int y = level_y[i];
                sub_relation[(level_x[i])][(level_y[i])] = level_y[i - j];
                sub_relation_num[x][y] ++;
                //一条线上的所有相关relation全部需要加一
                int temp = sub_relation[(level_x[i])][(level_y[i])];
                for (int k = level_x[i] + 1; k <= file_num; ++k) {
                    sub_relation_num[k][temp] ++;
                    temp = sub_relation[k][temp];
                }
            }
        }
    }

    //将命令及其参数存进数组
    //注意：每条命令是按照其对应顺序存进对应编号数组
    //如：一号为que 则que——name【1】 二号为re 则remove【1】 为空 【2】号才为目标编号
    for (int i = 1; i <= order_num; ++i) {
        scanf("%s",&(*(order[i])));
        if(strcmp(order[i],"query") == 0){
            scanf("%s",&(*que_name[i]));
            for (int j = 1; j <= file_num; ++j) {
                if(strcmp(que_name[i],file_name[j]) == 0){
                    printf("%d\n",sub_relation_num[(level_x[j])][(level_y[j])]);
                    break;
                }
            }
        }else if(strcmp(order[i],"remove") == 0) {
            scanf("%s", &(*remove_name[i]));
            for (int j = 1; j <= file_num; ++j) {
                if(strcmp(remove_name[i],file_name[j]) == 0){
                    //分两次进行：
                    //第一步把其上部的母结构全部减count
                    int temp = sub_relation[(level_x[j])][(level_y[j])];
                    for (int k = level_x[j] + 1; k <= file_num; ++k) {
                        sub_relation_num[k][temp] -= sub_relation_num[level_x[j]][level_y[j]];
                        temp = sub_relation[k][temp];
                    }
                    //第二部 把其子结构全部清空
                    //清空其本身
                    sub_relation_num[(level_x[j])][(level_y[j])] = 0;
                    //找到子结构中sub_relation等于其y值的
                    int temp2 = sub_relation[(level_x[j])][(level_x[j])];
                   // wrap(temp2,j);
                }
            }
        }
        getchar();
    }
}
void wrap(int x,int j) {
    for (int l = level_x[j] - 1; l > 0; --l) {
        for (int k = 1; k <= count[level_x[l]]; ++k) {
            if (sub_relation[l][k] == x) {
                sub_relation_num[l][k] = 0;
                wrap(sub_relation[l][k],j);
            }
        }

    }
}
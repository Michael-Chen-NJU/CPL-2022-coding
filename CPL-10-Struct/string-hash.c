#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
int hash(char *s);
typedef struct Link{
    int count;
    char *array;
    struct Link *next;
}Link ;
int main(){

    int m, q;
    scanf("%d %d",&m,&q);
    N = 5 * m ;
    Link *Linklist[N];
    getchar();
    //将每一个输出的hash对应到N里面，每一个指针代表字符串的地址
    //添加操作
    for (int i = 0; i < N; ++i) {
        Linklist[i] = (Link *)malloc(sizeof (Link));
    }

    //输入一个字符串，输入到hash函数中，计算所得值，并添加到对应下标的链表中
    for (int i = 0; i < m; ++i) {
        char *String = (char *) malloc(sizeof (char) * 1000);
        scanf("%s",String);
        int StrLen = 0;
        while(*(String + StrLen) != '\0'){
            StrLen ++;
        }
        char *string = (char *) malloc(sizeof (char) * (StrLen + 1));
        strcpy(string,String);
        free(String);
        int temp = hash(string);
        //printf("%d\n",hash(string));
        Link *new = (Link *)malloc(sizeof (Link));
        new ->array = string;
        new ->count ++;
        //把老地址接到新结构的pp上
        new ->next = Linklist[temp];
        //把新结构的头作为整体的头
        Linklist[temp] = new;
    }

    //查找操作
    //scanf输入到hash函数中，计算所得值，是查找，则遍历链表查找相应返回值的链表中的元素
    for (int i = 0; i < q; ++i) {
        char *Quest = (char *) malloc(sizeof (char) * 1000);
        scanf("%s", Quest);
        int StrLen = 0;
        while(*(Quest + StrLen) != '\0'){
            StrLen ++;
        }
        char *quest = (char *) malloc(sizeof (char) * (StrLen + 1));
        strcpy(quest,Quest);
        free(Quest);
        int temp = hash(quest);
        //printf("%d\n",temp);
        int is_same = 0;
        Link *copy;
        copy = Linklist[temp];
        while (copy -> next != NULL) {
            for (int j = 0; j < copy->count; ++j) {
                if (strcmp(quest, copy -> array) == 0) {
                    printf("Yes\n");
                    is_same = 1;
                    break;
                }
            }
            copy = copy ->next;
            if(is_same == 1){
                break;
            }
        }
        if(is_same == 0){
            printf("No\n");
        }
        free(quest);
    }
}
int hash(char *s){
    int len = strlen(s);
    int ret = 0;
    for(int i = 0;i < len; i++) {
        ret = (ret + s[i] * (i + 1)) % N;
    }
    return ret;
}
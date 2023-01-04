//
// Created by HW on 2022/12/19.
//
//由于实现链表的功能（初始化、插入、查询、删除）
//与解决约瑟夫问题是两个不同的步骤和模块，故为了区分写成多个文件
#include <stdio.h>
#include <assert.h>
#include "ll/ll.h"

#define NUM 10

void SitAroundCircle(Linkedlist *list, int num);

void KillUntilOne(Linkedlist *list);

int GetSurvivor(const Linkedlist *list);


int main() {
    for (int i = 1; i <= NUM; ++i) {
        Linkedlist list;
        //对于函数而言必需要传一个指针进去，否则所有改动只是在copy上改动
        Init(&list);


        //对于约瑟夫问题来说，第一个要实现的函数为：围成圈圈
        SitAroundCircle(&list, i);
        //printf("%p", Search(&list, i - 1));
        //Print(&list);
        //GetSurvivor(&list);
        //第二个函数：杀的只剩一个人
        KillUntilOne(&list);

        //第三个函数：找到幸存者
        int survivor = GetSurvivor(&list);
        printf("%d : %d\n", i, survivor);

        Free(&list);
    }
    return 0;
}

void SitAroundCircle(Linkedlist *list, int num) {
    for (int i = 1; i <= num; ++i) {
        //加入一个编号为i的人
        Insert(list, list->tail, i);
    }
}

void KillUntilOne(Linkedlist *list) {
    Node *node = list->head;

    while (!IsSingleton(list)) {
        Delete(list, node);
        node = node->next;
    }
}

int GetSurvivor(const Linkedlist *list) {
    assert(IsSingleton(list));

    return GetHeadVal(list);
}
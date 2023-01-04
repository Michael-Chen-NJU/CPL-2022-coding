//
// Created by HW on 2022/12/19.
//
#include <stdio.h>
#include "ll.h"
#include <stdlib.h>

//初始化操作 将头指针和尾指针置空
void Init(Linkedlist *list) {
    list->head = NULL;
    list->tail = NULL;
}

//加入值为val的新节点的操作
void Append(Linkedlist *list, int val) {
    Node *node = malloc(sizeof(*node));
    if (node == NULL) {
        printf("Error: malloc failed in Append\n");
        return;
    }
    //赋值
    node->val = val;

    if (IsEmpty(list)) {
        list->head = node;
    } else {
        //通用情况
        //把上一个结尾的next指到新开辟的node
        list->tail->next = node;
    }
    //把尾指针更新为node
    list->tail = node;
    //把新的尾指针的next指到head
    list->tail->next = list->head;
}

void Insert(Linkedlist *list, Node *prev, int val) {
    Node *node = malloc(sizeof(*node));
    if (node == NULL) {
        printf("Error: malloc failed in Append\n");
        return;
    }
    //赋值
    node->val = val;


    if (IsEmpty(list)) {
        list->head = node;
        //把尾指针更新为node
        list->tail = node;
        //把新的尾指针的next指到head
        list->tail->next = list->head;
    } else {
        //定义一个next的节点作为pre原来的下一个节点
        Node *next = list->tail->next;
        //通用情况
        //把pre暂时作为链表尾
        list->tail = prev;
        //把上一个结尾的next指到新开辟的node
        list->tail->next = node;
        //把尾指针更新为node
        list->tail = node;
        //把新的尾指针的next指到原来的next节点
        list->tail->next = next;
    }

}

void Delete(Linkedlist *list, Node *prev) {
    //普遍情况
    Node *cur = prev->next;
    Node *next = cur->next;
    prev->next = next;

    //如果只剩下最后一个节点或者list本身就是空的
    if (IsSingleton(list)) {
        list->head = NULL;
        list->tail = NULL;

        free(cur);
        return;
    } else if (IsEmpty(list)) {
        list->head = NULL;
        list->tail = NULL;
        return;
    }


    //如果删掉的是头节点
    if (cur == list->head) {
        list->head = next;
    }
    //如果删掉的是尾节点
    if (cur == list->tail) {
        list->tail = prev;
    }

    free(cur);
}

void Print(const Linkedlist *list) {
    if (IsEmpty(list)) {
        return;
    }
    //每当要遍历链表时 需要开一个新的节点来遍历
    Node *node = list->head;
    do {
        printf("%d ", node->val);
        node = node->next;
    } while (node != list->head);
}

Node *Search(const Linkedlist *list, int val) {
    Node *search = list->head;
    do {
        if (search->val == val) {
            return search;
        } else {
            search = search->next;
        }
    } while (search != list->head);
    return NULL;
}

bool IsEmpty(const Linkedlist *list) {
    return list->head == NULL;
}

bool IsSingleton(const Linkedlist *list) {
    //最后一个的情况 最后剩下的头和尾节点相等且不是空指针
    return list->head == list->tail && list->head != NULL;
}

int GetHeadVal(const Linkedlist *list) {
    if (IsEmpty(list)) {
        return -1;
    }
    return list->head->val;
}

void Free(Linkedlist *list) {
    while (!IsEmpty(list)) {
        Delete(list, list->head);
    }
}
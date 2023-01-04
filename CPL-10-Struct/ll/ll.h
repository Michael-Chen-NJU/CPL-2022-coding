//
// Created by HW on 2022/12/19.
//

//常量是什么不重要 重要的是必须是唯一的
#ifndef CLION_CODE_LL_H
#define CLION_CODE_LL_H

//拷贝一份stdbool.h的内容放在代码中
#include <stdbool.h>

//对于如约瑟夫.c这个文件如果即包含了ll.h 又包含了stdbool.h
//则会出现struct 函数等重复定义 这是不允许的
//为了保持这样的保持架构 则要用 #ifdef这样的操作
//第一次碰到ifdef CHENZIANG 由于未被定义过 故底下代码可见
//第二次碰到ifdef CHENZIANG 由于已经被定义过 故底下代码不可见
//保证了不会出现重复定义


//定义区
//定义每一个节点的结构体
typedef struct node {
    int val;
    struct node *next;
} Node;

//定义每个链表的头节点指针、尾节点指针
//也就代表了一个链表
//头节点永远要指向第一个节点
//尾节点永远要指向最后一个节点
typedef struct ll {
    Node *head;
    Node *tail;
} Linkedlist;


//函数区
//ll需要支持哪些函数
//具体实现在.c文件中实现
void Init(Linkedlist *list);

void Append(Linkedlist *list, int val);

void Insert(Linkedlist *list, Node *prev, int val);

void Print(const Linkedlist *list);

/**
 * @brief search for the node that is same with the needed val
 * @param list
 * @param val
 * @return with the needed node's pointer or NULL
 */
Node *Search(const Linkedlist *list, int val);

void Delete(Linkedlist *list, Node *node);

bool IsEmpty(const Linkedlist *list);

bool IsSingleton(const Linkedlist *list);

/**
 * @brief Return -1 if list is empty
 * @param list
 * @return
 */
int GetHeadVal(const Linkedlist *list);

void Free(Linkedlist *list);

#endif //CLION_CODE_LL_H

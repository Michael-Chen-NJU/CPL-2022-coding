//
// Created by HW on 2022/12/3.
//
#include <stdio.h>
#include <string.h>
//定义结构体的本意就是制作类型
struct stu {
    char name[30];
    int age;
    char sex;
    int weight;
};
union student{
    int a;
    char b;
    char c[20];
};
int main()
{
    struct stu cls[20] = {"zhangsan" , 18,'M',100,
            "lisi",19,};
    int a[2][2] = {10,10,10,10};
    struct stu zhangsan = {"zhangsan" , 18,'M',100};
    strcpy(zhangsan.name ,"go fuck yourself");
    zhangsan.age = 18;
    zhangsan.sex = 'M';
    printf("%s",cls[1]);
}


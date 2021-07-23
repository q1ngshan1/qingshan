#include<stdlib.h>
#include<stdio.h>
/*
typedef struct LNode LNode 把struct LNode类型定义一个名字LNode
typedef struct LNode *LinkList  
要表示一个单链表时,只需声明一个头指针,指向单链表第一个结点
LNode *L; 相当于LinkList L;
*/
typedef struct LNode  //定义单链表结点类型
{
    int data;          //每个结点存放一个数据元素
    struct LNode *next;  //指向下一个结点
}LNode,*LinkList;

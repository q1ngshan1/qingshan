#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/*
    如何判空
    如何判断结点p是否在表头/表尾
    如何在表头、表中、表尾插入/删除一个结点
*/

bool InitLinkList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode)); //分配头结点
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;            //输入数据
    int n;            //当前为第几个结点
    LNode *s, *r = L; //r为表尾指针
    printf("请输入第%d个结点的值,输入9999结束");
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode)); //分配新结点
        s->data = x;
        r->next = s;
        r = s;
        printf("请输入第%d个结点的值:", ++n);
        scanf("%d", &x);
    }
    r->next = NULL; //表尾指针置空
    return L;
}
//按位查找，返回第i个元素
LNode *getElem(LinkList L, int i)
{
    if (i < 1)
        return NULL; //判断i值是否合法
    LNode *p = L;    //扫描结点的指针
    int n = 0;       //当前扫描的是第几个结点
    while (p != NULL && n < i)
    {
        p = p->next;
        n++;
    }
    return p;
}

//按值查找,找到数据域==e的结点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L; //扫描结点的指针
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
//统计表长
int Length(LinkList L)
{
    int length = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

//头插法建立单链表
LinkList List_HeatInsert(LinkList &L)
{
    LNode *s;
    int x;
    int n = 1;
    printf("请输入第%d个结点的值,输入9999结束", n);
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        printf("请输入第%d个结点的值", ++n);
        scanf("%d", &x);
    }
    return L;
}
//后插操作,在p结点之后插入结点s
bool InserNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool
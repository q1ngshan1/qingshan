#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头节点
    if (L == NULL)                      //内存不足,分配失败
        return false;
    L->next = NULL; //头节点之后暂时还没有节点
    return true;
}
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;  //指针p 指向当前扫描到的结点
    int j = 0; //当前p指向的是第几个结点
    p = L;     //L指向头结点，头结点是第0个结点(不存数据)
    while (p != NULL && j < i - 1)
    { //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL) //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//后插操作,在p节点之后插入元素e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;
    s->data = e; //用节点s保持数据元素e
    s->next = p->next;
    p->next = s; //将节点s连接到p之后
    return true;
}
//前插操作:在p节点之前插入节点s
bool InserPrioNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) //内存分配失败
        return false;
    s->next = p->next;
    p->next = s;       //新结点s连接到p之后
    s->data = p->data; //将p中元素复制到s中
    p->data = e;       //p中元素覆盖为e
    return true;
}
//按位序删除结点
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0; //当前p指针指向的是第几个节点
    p = L;
    while ((p != NULL && j < i - 1))
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *q = p->next; //令q指向被删除结点
    e = q->data;        //用e返回元素的值
    p->next = q->next;  //将被删除节点*q的指针域赋给*p节点，将*q节点从链中断开
    free(q);            //释放节点的存储空间
    return true;        //删除成功
}

//删除指定结点p
bool DeleteNode(LNode *p)
{
    
}
//按位查找,返回第i个元素
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;                  //指针p指向当前扫描到的结点
    int j = 0;                 //当前p指针指向的是第几个结点
    p = L;                     //L指向头结点,头结点是第0个结点
    while (p != NULL && j < i) //循环找到第i个结点
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找，找到数据域==e的结点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p !NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
int Length(LinkList L)
{
    LNode *p = L;
    int len = 0; //统计表长
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L) //正向建立单链表
{
    int x; //输入数据
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; //r为表位指针
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; //r指向新的表尾结点
        sacnf("%d", &x);
    }
    r->next = NULL; //尾结点指针置空
    return L;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L) //逆向建立单链表
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next = NULL;                      //初始为空链表
    sanf("%d", &x);                      //输入结点的值
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode)); //创建新结点
        s->data = x;
        s->next = L->next; //将新申请的结点插入第一个位置，第一个结点插入时,next指针为空
        L->next = s;       //将新链表插入表中,L为头指针
        scanf("%d", &x);
    }
    return L;
}
int main()
{
    LinkList L;
    InitList(L);
    return 0;
}

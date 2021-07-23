#include<stdio.h>
#include<stdlib.h>
typedef struct DLNode
{
    int data;  //数据域
    struct DLNode *next,*prior;  //前驱和后继指针
}DLNode,*DLinkList;

/*
    如何判空
    如何判断结点p是否在表头/表尾
    如何在表头、表中、表尾插入/删除一个结点
*/


//初始化双链表
bool InitDLinkList(DLinkList &L)
{
    DLNode *p;  //指向当前扫描的结点
    int n=1; //当前扫描的结点
    L=(DLNode *)malloc(sizeof(DLNode));  //分配一个头结点
    if(L==NULL)
        return  false;   //内存不足,分配失败
    L->prior=NULL;  //头结点的前驱指针永远指向NULL
    L->next =NULL;  //头结点之后还没有结点
    return true;
}

//尾插法建立双链表
DLinkList DLinkListInsert(DLinkList &L)
{
    int x;  //输入数据
    int n=1; //当前是第几个结点
    L=(DLinkList)malloc(sizeof(DLNode));
    DLNode *s,*r=L;  //r是表尾指针
    printf("请输入第%d个结点的值:",n);
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(DLNode *)malloc(sizeof(DLNode));  //分配一个新结点
        s->data=x;  //把输入数据存入新结点的数据域
        r->next=s;  //把表尾的后继指针指向新结点
        s->prior=r;  //把s的前驱指针指向表尾结点
        r=s;   //r指向新的表尾结点
        printf("请输入第%d个结点的值:",++n);
        scanf("%d",&x);
    }
    r->next=NULL;  //表尾指针置空
    return L;
}
//后向遍历双链表打印数据
void printDLinkList(DLinkList L)
{
    int n=1;  //当前扫描到是第几个结点
    DLNode *p=L->next; //指向当前扫描的结点
    while(p!=NULL)
    {
        printf("第%d个结点的值为%d\n",n,p->data);
        n++;
        p=p->next;
    }
}
int main()
{
    DLinkList L;
    InitDLinkList(L);
    DLinkListInsert(L);
    printDLinkList(L);
    return 0;
}

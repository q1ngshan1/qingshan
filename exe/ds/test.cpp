#include <stdlib.h>
#include <stdio.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;


int main()
{
    LinkList L;
    int x;
    L=(LinkList)malloc(sizeof(LNode));  //创建头指针
    LNode *s,*r=L;   //r为表尾指针
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode *)malloc(sizeof(LNode));  //创建新结点
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    int i=1;
    LNode *p=L->next; //扫描结点的指针
    while(p!=NULL)
    {
        printf("第%d个结点的值为%d\n",i,p->data);
        p=p->next;
        i++;
    }
    return 0;
}



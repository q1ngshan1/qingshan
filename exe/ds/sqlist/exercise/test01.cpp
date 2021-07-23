#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;

//顺序表递增有序,插入元素x，仍递增有序
/*  int find(SqList &L, int x)
{
    for (int i = 0; i < L->length; i++)
    {
        if (x < L->data[i])
            return i;
    }
    return i;
}
*/
void insert(SqList &L)
{

}

//删除顺序表中所有值为x的数据元素
void deletex(SqList &L, int x)
{
    int k=0;
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]!=x)
        {
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length=k;
}

//从顺序表中删除给定值到t之间(包含s和t)的所有元素
bool Delete(SqList &L, int t)
{
    return NULL;
}

//从有序表中删除所有值重复的元素
bool Delete(SqList &L)
{
    return NULL;
}

//初始化顺序表
void InitList(SqList &L)
{
    printf("请输入表长:");
    scanf("%d",&L.length);
    for(int i=0;i<L.length;i++)
    {
        scanf("%d",&L.data[i]);
    }
}
//打印顺序表
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("data[%d]=%d \n",i,L.data[i]);
    }
    printf("表长为%d",L.length);
}
int main()
{
    int x=3;
    SqList L;
    InitList(L);
    deletex(L,3);
    PrintList(L);
    return 0;
}
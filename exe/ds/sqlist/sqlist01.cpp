#include <stdio.h>
#include <stdlib.h>
//静态分配实现顺序表

#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE] = {0};
    int length;
} SqList;
void InitList(SqList *L)
{
    L->length = 0;
}
int ListInsert(SqList *L, int i, int e) //在第i个位置插入元素e
{
    if (i < 1 || i > L->length + 1) //判断i的范围是否有效
        return 0;
    if (L->length >= MAXSIZE) //当前存储空间已满 不能插入
        return 0;
    for (int j = L->length; j >= i; j--) //将第i个元素之后的元素后移
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e; //在位置i处放入e
    L->length++;        //顺序表长度加一
    return 1;
}
int ListDelete(SqList *L, int i, int *e)
{
    if (i < 1 || i > L->length)
        return 0;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j]; 
    }
    return 1;
}
int main()
{
    SqList L;
    InitList(&L);
    L.length = 5;
    int e = -1;
    ListInsert(&L, 2, 3);
    ListDelete(&L, 2, &e);
    for (int i = 0; i < MAXSIZE; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    printf("%d", e);
    return 0;
}

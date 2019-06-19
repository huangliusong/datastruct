//
//  a.c
//  chapter7.3
//
//  Created by liusong huang on 2019/6/19.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include "a.h"
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
//不带头节点的链表
void Del_x(Linklist &L, ElemType x)
{
    LNode *p;
    if (L == NULL)
    { //p指向待删除节点
        return;
    }
    if (L->data == x)
    {
        p = L; //p指向待删除节点
        L = L->data;
        free(p);
        Del_x(L, x);
    }
    else
    {
        Del_x(L->data, x); //递归调用
    }
}

//解法1
void Delete_x1(LinkList &L, ElemType x)
{
    //L 为带头结点的单链表，本算法删除L中的所有值为x的节点
    LNode *p = L->next, *pre = L, *q; //
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(p);
        }
        else
        {
            pre = p;
            p = p->next;
        } //else end
    }     //while end
}

//解法2：采用尾插法
void Delete_x2(LinkList &L, ElemType x)
{
    //r指向尾节点，其初值为头节点
    LNode *p = L->data, *r = L, *p;
    while (p != NULL)
    {
        if (p->data != x)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next; //继续扫描
            free(q);     //释放空间
        }
    }
    r->next = NULL;
}

void print_element(LinkList L)
{
    //从尾部到头部输出单链表中到每个元素
    if (L->next != NULL)
    {
        print_element(L->next); //递归
    }
    prinft(L->data);
}

LinkList Delete_Min(LinkList &L)
{
    //L是带头节点的单链表，本算法删除其最小节点
    LNode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p; //保存最小值结点及其前驱
    while (p != NULL)
    {
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p; //继续扫描下一个节点
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}

LinkList reverse_1(LinkList L)
{
    //L是带头节点的单链表，本算法将L就地逆置
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
}

void RangeDelete(LinkList &L, int min, int max)
{
    LNode *pre = L, *p = L->link;
    while (p->next != null)
    {
        //寻找到被删除的节点，删除
        if (p->data > min && p->data < max)
        {
            pre->link = p->link;
            free(p);
            p = pre->link;
        }
        else //没有寻找到节点
        {
            pre = p;
            p = p->link;
        }
    }
}

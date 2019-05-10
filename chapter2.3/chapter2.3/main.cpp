//
//  main.cpp
//  chapter2.3
//  单链表
//  Created by liusong huang on 2019/5/10.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int  ElemEype;
typedef struct LNode{
    ElemEype data;
    struct LNode *next;
}LNode,*LinkList;
//此行的LNode是结构体struct LNode的一个别名
//*LinkList也是结构体struct LNode的一个别名
//换言之LinkList是结构体struct LNode类型的指针的别名
//也就是说  struct LNode *p;这条语句等同于LinkList p;

//头插法新建链表
LinkList CreateList1(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while (x!=9999) {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}


LinkList CreateList2(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while (x!=9999) {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;//指向新的表尾节点
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

//n按序号查找节点值
LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if (i==0) {
        return L;
    }
    if (i<1) {
        return NULL;
    }
    while (p&&j<i) {
        p=p->next;
        j++;
    }
    return p;
}

//按照值查找
LNode *LocateElem(LinkList L,ElemEype e){
    LNode *p=L->next;
    while (p!=NULL&&p->data!=e) {
        p=p->next;
    }
    return p;
}

//新节点插入第i个位置
bool ListFrontInsert(LinkList L,int i,ElemEype e){
    LinkList p=GetElem(L, i-1);
    if (NULL==p) {
        return false;
    }
    LinkList s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}


//删除节点
bool ListDelete(LinkList L,int i){
    LinkList p=GetElem(L, i-1);
    if (NULL==p) {
        return false;
    }
    LinkList q;
    q=p->next;
    p->next=q->next;
    free(q);
    return true;
}

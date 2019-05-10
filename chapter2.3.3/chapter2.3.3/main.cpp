//
//  main.cpp
//  chapter2.3.3
//  双向链表头插法
//  Created by liusong huang on 2019/5/10.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

DLinkList Dlist_head_insert(DLinkList &DL){
    DNode *s;
    int x;
    DL=(DLinkList)malloc(sizeof(DNode));
    DL->next=NULL;
    DL->prior=NULL;
    scanf("%d",&x);
    while (x!=9999) {
        s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;
        s->next=DL->next;
        if (DL->next!=NULL) {
            DL->next->prior=s;
        }
        s->prior=DL;
        DL->next=s;
        scanf("%d",&x);
    }
    return DL;
}

//双向链表尾插法
DLinkList Dlist_tail_insert(DLinkList &DL){
    int x;
    DL=(DLinkList)malloc(sizeof(DNode));//带头节点的链表
    DNode *s,*r=DL;
    DL->prior=NULL;
    scanf("%d",&x);
    while (x!=9999) {
        s=(DNode*)malloc(sizeof(DNode));
        s->data=x;
        r->next=s;
        s->prior=r;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return DL;
}

//按序号查找节点值
DNode *GetElem(DLinkList DL,int i){
    int j=1;
    DNode *p=DL->next;
    if (i==0) {
        return DL;
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


//新节点插入第i个位置
bool DListFrontInsert(DLinkList DL,int i,ElemType e){
    DLinkList p=GetElem(DL, i-1);
    if (NULL==p) {
        return false;
    }
    DLinkList s=(DLinkList)malloc(sizeof(DNode));
    s->data=e;
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}

//删除第i个节点
bool DListDelete(DLinkList DL,int i){
    DLinkList p=GetElem(DL, i-1);
    if (NULL==p) {
        return false;
    }
    DLinkList q;
    q=p->next;
    if (q==NULL) {//删除的元素不存在
        return false;
    }
    p->next=q->next;
    if (q->next!=NULL) {
        q->next->prior=p;
    }
    free(q);//释放对应节点的空间
    return true;
}

//链表打印
void PrintDList(DLinkList DL){
    DL=DL->next;
    while (DL!=NULL) {
        printf("%3d",DL->data);
        DL=DL->next;
    }
    printf("\n");
}



int main(){
    printf("链表:\n");
    DLinkList DL;
    DLinkList search;
    Dlist_tail_insert(DL);
    PrintDList(DL);
    search=GetElem(DL, 2);
    if (search!=NULL) {
        printf("按序号查找成功\n");
        printf("%d\n",search->data);
    }
    DListFrontInsert(DL, 3, 99);
    PrintDList(DL);
    DListDelete(DL, 2);
    PrintDList(DL);
}

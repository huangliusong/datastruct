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

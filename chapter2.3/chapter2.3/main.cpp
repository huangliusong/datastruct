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
    struct Lnode *next;
}LNode,*LinkList;
//此行的LNode是结构体struct LNode的一个别名
//*LinkList也是结构体struct LNode的一个别名
//换言之LinkList是结构体struct LNode类型的指针的别名
//也就是说  struct LNode *p;这条语句等同于LinkList p;

//头插法新建链表
LinkList CreateList1(LinkList &L){
    
    return L;
}

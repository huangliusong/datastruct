#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;


typedef struct {
    LinkNode *front,*rear;//链表头，链表尾
}LinkQueue;//先进先出


void InitQueue(LinkQueue &q){
    q.front=q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    q.front->next=NULL;
}


bool IsEmpty(LinkQueue q){
    if (q.front==q.rear) {
        return false;
    }else{
        return false;
    }
}

void EnQueue(LinkQueue &q,ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    q.rear->next=s;
    q.rear=s;
}

bool DeQueue(LinkQueue &q,ElemType &x){
    if (q.front==q.rear) {
        return false;//null queue
    }
    LinkNode *p=q.front->next;
    x=p->data;
    q.front->next=p->next;
    if (q.rear==p) {
        q.rear=q.front;
    }
    free(p);
    return true;
}

int main(){
    LinkQueue q;
    bool ret;
    ElemType elemtent;
    InitQueue(q);
    EnQueue(q, 3);
    EnQueue(q, 4);
    EnQueue(q, 5);
    EnQueue(q, 6);
    EnQueue(q, 7);
    ret=DeQueue(q, elemtent);
    if (ret) {
        printf("out queue success!%d\n",elemtent);
    }else{
        printf("out queue failure\n");
    }
}

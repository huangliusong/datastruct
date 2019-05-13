#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
//循环队列
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//数组，存储MaxSize-1个
    int front,rear;//队列头 队列尾
}SqQueue;

void InitQueue(SqQueue &q){
    q.rear=q.front=0;
}

//判空
bool isEmpty(SqQueue &q){
    if (q.rear==q.front) {
        return true;
    }else{
        return false;
    }
}

//入队
bool EnQueue(SqQueue &q,ElemType x){
    if ((q.rear+1)%MaxSize==q.front) {
        return false;
    }
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MaxSize;
    return true;
}


//出队
bool DeQueue(SqQueue &q,ElemType &x){
    if (q.rear==q.front) {
        return false;
    }
    x=q.data[q.front];
    q.front=(q.front+1)%MaxSize;
    return true;
}


int main(){
    SqQueue q;
    bool ret;
    ElemType element;
    InitQueue(q);
    ret=isEmpty(q);
    if (ret) {
        printf("队列为空\n");
    }else{
        printf("队列不为空\n");
    }
    EnQueue(q, 3);
    EnQueue(q, 4);
    EnQueue(q, 5);
    ret=EnQueue(q, 6);
    ret=EnQueue(q, 7);
    if (ret) {
        printf("success!\n");
    }else{
        printf("failure\n");
    }
    ret=DeQueue(q, element);
    if (ret) {
        printf("success!element is %d\n",element);
    }else{
        printf("failure!\n");
    }
    ret=DeQueue(q, element);
    if (ret) {
        printf("success!element is %d\n",element);
    }else{
        printf("failure!\n");
    }
    ret=DeQueue(q, element);
    if (ret) {
        printf("success!element is %d\n",element);
    }else{
        printf("failure!\n");
    }
    ret=EnQueue(q,8);
    if (ret) {
        printf("enter success!\n");
    }else{
        printf("enter failure!\n");
    }
}

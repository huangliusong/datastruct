
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define ElemType int
#define MAXQSIZE 6


using namespace std;


typedef struct
{
    ElemType *base;
    int front;
    int rear;
    int tag = 0;
}SqQueue;


//tag t队列初始化
int init_queue(SqQueue &sq){
    sq.base=(ElemType*)malloc(MAXQSIZE*sizeof(ElemType));
    if (!sq.base) {
        exit(OVERFLOW);
    }
    sq.front=sq.rear=0;
    return OK;
}


//tag d入队

int main(){
    SqQueue sq;
    init_queue(sq);
    printf("init success!\n");
}

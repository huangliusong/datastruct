#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int  ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;


void InitStack(SqStack &S){
    S.top=-1;
}

bool StackEmpty(SqStack &s){
    if (s.top==-1) {
        return true;
    }else{
        return false;
    }
}

//入栈
bool Push(SqStack &s,ElemType x){
    if (s.top==MaxSize-1) {
        printf("栈溢出");
        return false;
    }
    s.data[++s.top]=x;
    return false;
}

//出栈
bool Pop(SqStack &s,ElemType &x){
    if (-1==s.top) {
        return false;
    }
    x=s.data[s.top--];
    return true;
}

//
int main(){
    SqStack stack;
    bool flag;
    ElemType m;
    InitStack(stack);
    flag=StackEmpty(stack);
    if (flag) {
        printf("这个栈为空\n");
    }
    Push(stack, 1);
    Push(stack, 3);
    Push(stack, 4);
    Push(stack, 5);
    flag=StackEmpty(stack);
    if (flag) {
        printf("这个栈为空\n");
    }
    printf("top:%d\n",stack.top);
    flag=Pop(stack, m);
    if (flag) {
        printf("pop element:%d\n");
    }
    system("pause");
    return 0;
}


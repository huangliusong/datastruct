#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define maxsize 6


typedef struct node{
    int data[maxsize];
    int front;
    int rear;
    int tag;
}seq;


//init
void init(seq *q){
    q->front=0;
    q->rear=0;
    q->tag=0;
}

int empty(seq q){
    if (q.front==q.rear&&q.tag==0) {
        return 1;
    }
    else
        return 0;
}

// 入队操作
int insert(seq *q,int e){
    if (q->front==q->rear&&q->tag==1) {
        cout<<"队列满了";
        return 1;
    }else{
        q->data[q->rear]=e;
        q->rear=q->rear+1;
        q->tag=1;
        return 1;
    }
}

//out queue
int del(seq *q,int *e){
    if (empty(*q)) {
        cout<<"队列是空队列";
        return 0;
    }else{
        *e=q->data[q->front];
        q->front=q->front+1;
        q->tag=0;
        return 1;
    }
}


//dispaly queue
int dis(seq q)
{
    int i;
    if(empty(q))
    {
        return 0;
    }
    if(q.front<q.rear)
    {    for(i=q.front;i<=q.rear;i++)
        cout<<q.data[i]<<" ";
    }
    else
    {
        for(i=q.front;i<=q.rear+maxsize;i++)
            cout<<q.data[i%maxsize]<<" ";
    }
    cout<<endl;
    return 0;
}

int get(seq q,int *e)
{
    if(q.front==q.rear)
        return 0;
    else
    {
        *e=q.data[q.front];
        return 1;
        
    }
    
}
void clear(seq *q)
{
    q->front=q->rear=0;
}


int main()
{
    seq q;
    int x;
    init(&q);
    cout<<"1入队！"<<endl;
    insert(&q,1);
    
    cout<<"2入队！"<<endl;
    insert(&q,2);
    
    cout<<"3入队！"<<endl;
    insert(&q,3);
    
    cout<<"4入队！"<<endl;
    insert(&q,4);
    
    cout<<"1出队！"<<endl;
    del(&q,&x);
    cout<<"队列首元素为："<<x<<endl;
    
    cout<<"2出队！"<<endl;
    del(&q,&x);
    cout<<"队列首元素为："<<x<<endl;
    
    cout<<"3出队！"<<endl;
    del(&q,&x);
    cout<<"队列首元素为："<<x<<endl;
    
    cout<<"5入队！"<<endl;
    insert(&q,5);
    
    cout<<"6入队！"<<endl;
    insert(&q,6);
    
    cout<<"7入队！"<<endl;
    insert(&q,7);
    
    printf("剩余队列元素为：");
    if(!empty(q))
    {
        for(int i=q.front;i<q.rear;i++)
        {
            cout<<q.data[i]<<" ";
        }
    }
}


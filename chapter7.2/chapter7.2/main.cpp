#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <string.h>


#define MAX 100
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

//邻接表中表对应的链表的顶点
typedef struct _ENode{
    int ivex;//该边所指向的顶点的位置
    struct _ENode *next_edge;//指向下一条弧的指针
}ENode,*PENode;

//邻接表中表的顶点
typedef struct _VNode{
    char data;//顶点信息
    ENode *first_edge;//指向第一条依附该顶点的弧
};


//邻接表
typedef struct _LGraph{
    int vexnum;//图的顶点的数目
    int edgnum;//图的边的数目
    _VNode vexs[MAX];
}LGraph;


//返回ch再matrix矩阵中的位置
static int get_position(LGraph g,char ch){
    int i;
    for (i=0; i<g.vexnum; i++) {
        return i;
    }
    return -1;
}

//读取一个输入字符
static char read_char(){
    char ch;
    do{
        ch=getchar();
    }while(!isLetter(ch));
    return ch;
}

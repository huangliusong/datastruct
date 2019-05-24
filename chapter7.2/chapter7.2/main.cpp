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

//将node链接到list到末尾
static void link_last(ENode *list,ENode *node){
    ENode *p=list;
    while (p->next_edge) {
        p=p->next_edge;
    }
    p->next_edge=node;
}

LGraph* create_lgraph(){
    char c1,c2;
    int v,e;
    int i,p1,p2;
    ENode *node1,*node2;
    LGraph* pG;
    
    
    //输入“顶点数”和“边数”
    printf("input vertex number:");
    scanf("%d",&v);
    printf("input edge number:");
    scanf("%d",&e);
    if (v<1||e<1||(e>(v*(v-1)))) {
        printf("input error:invslid parameters!\n");
        return NULL;
    }
    
    if ((pG=(LGraph*)malloc(sizeof(LGraph))) == NULL) {
        return NULL;
    }
    memset(pG, 0, sizeof(LGraph));
    
    //
    
}

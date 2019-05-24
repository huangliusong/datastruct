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
    // 初始化"顶点数"和"边数"
    pG->vexnum = v;
    pG->edgnum = e;
    // 初始化"邻接表"的顶点
        for(i=0; i<pG->vexnum; i++)
            {
                    printf("vertex(%d): ", i);
                    pG->vexs[i].data = read_char();
                    pG->vexs[i].first_edge = NULL;
                }
    
        // 初始化"邻接表"的边
        for(i=0; i<pG->edgnum; i++)
            {
                    // 读取边的起始顶点和结束顶点
                    printf("edge(%d): ", i);
                    c1 = read_char();
                    c2 = read_char();
            
                    p1 = get_position(*pG, c1);
                    p2 = get_position(*pG, c2);
            
                    // 初始化node1
                    node1 = (ENode*)calloc(1,sizeof(ENode));
                    node1->ivex = p2;
                    // 将node1链接到"p1所在链表的末尾"
                    if(pG->vexs[p1].first_edge == NULL)
                          pG->vexs[p1].first_edge = node1;
                    else
                            link_last(pG->vexs[p1].first_edge, node1);
                    // 初始化node2
                    node2 = (ENode*)calloc(1,sizeof(ENode));
                    node2->ivex = p1;
                    // 将node2链接到"p2所在链表的末尾"
                    if(pG->vexs[p2].first_edge == NULL)
                          pG->vexs[p2].first_edge = node2;
                    else
                            link_last(pG->vexs[p2].first_edge, node2);
                }
    
        return pG;
}

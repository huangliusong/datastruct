#include <stdio.h>
#include <stdlib.h>

typedef int  KeyType;
typedef struct BSTNode {
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;



int BST_Insert(BiTree &T,KeyType k){
    if (NULL==T) {
        T=(BiTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }else if(k==T->key)
        return 0;
    else if(k<T->key)
        return BST_Insert(T->lchild, k);
    else
        return BST_Insert(T->rchild, k);
}

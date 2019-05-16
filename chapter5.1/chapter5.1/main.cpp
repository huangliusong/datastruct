#include <stdarg.h>
//暂时保留
#define MAS_ARRAY_DIM 8

typedef int ElemType;

typedef struct {
    ElemType *base;
    int dim;//数据的维数
    int *bounds;
    int *constans;
}Array;



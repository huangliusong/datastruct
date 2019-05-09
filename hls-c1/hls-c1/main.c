//
//  main.c
//  hls-c1
//
//  Created by liusong huang on 2019/3/17.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>
#define PI 3.1415926

int main(int argc, const char * argv[]) {
    int a,b;
    //定义两个指针
    int *pointer_1,*pointer_2;
    a=100;
    b=10;
    pointer_1=&a;
    pointer_2=&b;
    printf("%d,%d\n",a,b);
    printf("%d,%d",*pointer_1,*pointer_2);
    printf("\n");
     printf("%f\n",PI);
}

int max(int x,int y){
    int z;
    z=x>y?x:y;
    return z;
}

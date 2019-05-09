//
//  main.c
//  hls-c-lesson6
//指针
//  Created by liusong huang on 2019/4/24.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //声明
    void test1();
    void test2();
    void test3();
    //调用
    test1();
    test2();
    test3();
    
    return 0;
}

void test1(){
    printf("===============test1===============\n");
    int a=100,b=10;//定义整形变量a,b并初始化
    int * pointer_1,* pointer_2;//定义指向整型3数据的指针变量pointer_1,pointer_2
    pointer_1=&a;//把变量a的地址赋值给指针变量pointer_1
    pointer_2=&b;//把变量b的地址赋值给指针变量pointer_2
    printf("a=%d,b=%d\n",a,b);//输出变量a和b的指
    printf("值=>>* pointer_1=%d,*pointer_2=%d\n",*pointer_1,*pointer_2);
    printf("地址=>>* pointer_1=%o,*pointer_2=%o\n",pointer_1,pointer_2);
}

void test2(){
    printf("===============test2===============\n");
    int *p1,*p2,*p,a,b;
    printf("请输入两个整形数据：");
    scanf("%d,%d",&a,&b);//输入两个整数
    p1=&a;
    p2=&b;
    if (a<b) {
        p=p1;
        p1=p2;
        p2=p;
    }
    printf("a=%d,b=%d\n",a,b);
    printf("max=%d,min=%d\n",*p1,*p2);
}

void test3(){
    printf("===============test3===============\n");
    void swap(int *p1,int *p2);
    int a,b;
    int *pointer_1,*pointer_2;
    printf("please enter a and b:");
    scanf("%d,%d",&a,&b);
    pointer_1=&a;
    pointer_2=&b;
    if (a<b) {
        swap(pointer_1, pointer_2);
        printf("max=%d,min=%d\n",1,a,b);
        
    }
    
}

void swap(int *p1,int *p2){
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

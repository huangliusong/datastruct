//
//  main.c
//  hls-c-lesson7
//  指针引用数组
//  Created by liusong huang on 2019/4/24.
//  Copyright © 2019 liusong huang. All rights reserved.
//
#include <stdio.h>

int main(int argc, const char * argv[]) {
    void test5();
    test5();
    void test4();
    test4();
    void test();
    test();
    void test1();
    test1();
    
    int reverse(int x);
    int rev=reverse(123);
    printf("%d\n",rev);
    
    
    int isPalindrome(int x);
    int flag1=isPalindrome(1221);
    int flag2=isPalindrome(12211);
    printf("flag1=%d\n",flag1);
    printf("flag2=%d\n",flag2);
    
    
    void test3();
    test3();
    return 0;
    
    
}

void test(){
    printf("===========================\n");
    int a[10]={1,3,5,7,9,11,13,15,17,19};//定义a为包含10个整型数据的数组
    int * p;//定义p为指向整型变量的指针变量
    p=&a[0];//把a[0]元素的地址赋给指针变量p
    //获取数组长度sizeof(a)/sizeof(int)
    for (int i=0; i<sizeof(a)/sizeof(int); i++) {
        printf("%d\n",*p);
        p++;
    }
}


void test1(){
    printf("===========================\n");
    int a[10]={1,3,5,7,9,11,13,15,17,19};//定义a为包含10个整型数据的数组
    int * p;//定义p为指向整型变量的指针变量
    p=a;
    //获取数组长度sizeof(a)/sizeof(int)
    for (int i=0; i<sizeof(a)/sizeof(int); i++) {
        printf("%d\n",*p);
        p++;
    }
}


#define INT_MIN 0X80000000
#define INT_MAX 0X7FFFFFFF

int min = INT_MIN;
int max = INT_MAX;

int reverse(int x) {
    long int result = 0;
    while(x != 0) {
        result = result * 10 + x % 10;
        x = x/10;
        
        if (result < min)
            return 0;
        else if (result > max)
            return 0;
    }
    
    return result;
}


int isPalindrome(int x) {
    if(x<0){
        return 0;
    }
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return 0;
    }
    int reverteNumber=0;
    while(x>reverteNumber){
        reverteNumber=reverteNumber*10+x%10;
        x=x/10;
    }
    return x==reverteNumber||x==reverteNumber/10;
}


void test3(){
    int *p,i,a[10];
    p=a;
    printf("please enter 10 integer numbers:\n");
    for (i=0; i<10; i++) {
        scanf("%d",p++);
    }
    p=a;
    for (i=0; i<10; i++,p++) {
        printf(" %d ",*p);
    }
    printf("\n");
}


void test4(){
    void inv(int x[],int n);
    int i,a[10]={3,7,9,11,0,6,7,5,4,2};
    printf("The original array:\n");
    for (i=0; i<10; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    inv(a, 10);
    printf("The array been inverted:\n");
    for (i=0; i<10; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void inv(int x[],int n){
    int temp,i,j,m=(n-1)/2;
    for (i=0; i<=m; i++) {
        j=n-1-i;
        temp=x[i];
        x[i]=x[j];
        x[j]=temp;
    }
    return;
}

void test5(){
    void sort(int x[],int n);
    int i,*p,a[10];
    p=a;
    printf("please enter 10 integer numbers:\n");
    for (i=0; i<10; i++) {
        scanf("%d ",p++);
    }
    p=a;
    sort(p, 10);
    for (p=a,i=0;i<10; i++) {
        printf("%d ",*p);
        p++;
    }
    printf("\n");
}

void sort(int x[],int n){
    int i,j,k,t;
    for (i=0; i<n-1; i++) {
        k=i;
        for (j=i+1; j<n; j++) {
            if (x[j]>x[i]) {
                k=j;
                if (k!=i) {
                    t=x[i];
                    x[i]=x[k];
                    x[k]=t;
                }
            }
        }
    }
}

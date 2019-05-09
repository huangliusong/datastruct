//
//  main.c
//  hls-c-lesson3
//003.求整数之积
//  Created by liusong huang on 2019/4/22.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //#################1
//    // insert code here...
//    printf("Hello, World!\n");
//    int x,y,m;
//    printf("请输入x和y\n");
//    scanf("%d%d",&x,&y);
//    m=x*y;
//    printf("求和x*y=%d\n",m);
     //#################2
    //004.比较实数大小
    float a,b,c;
    printf("请输入:\n");
    scanf("%f%f",&a,&b);
    c=a>b?a:b;
    printf("MAX of (%f,%f) is %f",a,b,c);
    return 0;
}

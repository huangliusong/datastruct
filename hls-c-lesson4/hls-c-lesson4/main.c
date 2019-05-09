//
//  main.c
//  hls-c-lesson4
//005.字符的输出
//  Created by liusong huang on 2019/4/22.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
//    char ch,nch;
//    int count;
//    int k;
//
//    printf("Please input a string with a # in the end.\n");
//    scanf("%c",&ch);
//    while(ch != '#')    /* */
//    {
//        if(ch >= '0' && ch <= '9')
//        {
//            /* */
//            count = ch-'0'+1;    /* */
//            scanf("%c",&nch);    /* */
//            for(k=0;k<count;k++)    /* */
//                printf("%c",nch);
//        }
//        else
//            printf("%c",ch);    /* */
//        printf(" ");            /* */
//        scanf("%c",&ch);        /* */
//    }
//    printf("#\n");
    
    
    
    //006.显示变量所占字节数
    printf("The bytes of the variables are:\n");
    printf("int:%d bytes\n",sizeof(int));
    printf("char:%d byte\n",sizeof(char));
    printf("short:%d bytes\n",sizeof(short));
    printf("long:%d bytes\n",sizeof(long));
    printf("float:%d bytes\n",sizeof(float));
    printf("double:%d bytes\n",sizeof(double));
    printf("long double:%d bytes\n",sizeof(long double));
    
    //007.自增自减运算
    int a=5,b,c,i=10;
    b=a++;
    c=++b;
    printf("a = %d, b = %d, c = %d\n",a,b,c);
    printf("i,i++,i++ = %d,%d,%d\n",i,i++,i++);
    printf("%d\n",++i);
    printf("%d\n",--i);
    printf("%d\n",i++);
    printf("%d\n",i--);
    printf("%d\n",-i++);
    printf("%d\n",-i--);
    return 0;
}

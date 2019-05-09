//
//  main.c
//  C-lean1
//
//  Created by liusong huang on 2019/5/8.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int month;
    int day;
    int year;
}Date;

int main(int argc, const char * argv[]) {
    printf("用typedef\n");
    Date birthday;
    Date *p;
    birthday.year=1991;
    birthday.month=11;
    birthday.day=11;
    p=&birthday;
    printf("年%d\n",p->year);
     printf("月%d\n",p->month);
     printf("日%d\n",p->day);
    return 0;
}

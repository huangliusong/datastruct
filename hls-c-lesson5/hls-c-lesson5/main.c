//
//  main.c
//  hls-c-lesson5
//
//  Created by liusong huang on 2019/4/22.
//  Copyright © 2019 liusong huang. All rights reserved.
//

#include <stdio.h>

struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
} book = {"C 语言", "RUNOOB", "编程语言", 123456};



int main()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}

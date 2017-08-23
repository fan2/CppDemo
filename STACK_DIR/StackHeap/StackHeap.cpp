//
//  StackHeap.cpp
//  STACK_DIR
//
//  Created by faner on 2017/8/23.
//  Copyright © 2017年 zimushan. All rights reserved.
//

#include <cstdlib>
#include <iostream>

int a = 0;  // 全局初始化区
char *p1;   // 全局未初始化区

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!" << std::endl;
    
    int b;              // 栈
    char s[] = "abc";   // 栈
    char *p2;           // 栈
    
    // 123456/0在常量区，p3在栈上。
    char *p3 = "123456";
    
    // 全局（静态）初始化区
    static int c = 0;
    
    // 分配得来得10和20字节的区域就在堆区
    p1 = (char*)malloc(10);
    p2 = (char*)malloc(20);
    
    // 123456/0放在常量区，编译器可能会将它与p3所指向的"123456"，优化成一个地方。
    strcpy(p1, "123456");
    
    return EXIT_SUCCESS;
}

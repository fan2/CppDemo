//
//  main.cpp
//  STACK_DIR
//
//  Created by faner on 2017/8/16.
//  Copyright © 2017年 zimushan. All rights reserved.
//

#include <iostream>
#include <pthread.h>

// [What is the direction of stack growth in most modern systems?](https://stackoverflow.com/questions/664744/what-is-the-direction-of-stack-growth-in-most-modern-systems)

typedef enum
{
    _STACK_GROWS_DOWN,
    _STACK_GROWS_UP
}STACK_DIR;

static STACK_DIR
test_stack_direction()
{
    static char *addr = 0;
    char dummy;
    if (addr == 0)
    {
        addr = &dummy;
        return test_stack_direction();
    }
    else
    {
        return ((&dummy > addr) ? _STACK_GROWS_UP : _STACK_GROWS_DOWN);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i = 0; // dummy
    pthread_t tid = pthread_self();
    
    void* stackaddr = pthread_get_stackaddr_np(tid);
    std::cout << "stackaddr = " << stackaddr << std::endl;
    
    size_t stacksize = pthread_get_stacksize_np(tid);
    std::cout << "stacksize = " << stacksize << std::endl; // PTHREAD_STACK_MIN = 8K
    
    std::cout << "&i = " << static_cast<const void *>(&i) << std::endl;
    std::cout << "&tid = " << static_cast<const void *>(&tid) << std::endl; // struct
    
    int year = 2017;
    short month = 8;
    char day = 19;
    char wish[4]{0x11, 0x22, 0x33, 0x44};
    
    std::cout << "&year = " << static_cast<const void *>(&year) << std::endl;
    std::cout << "&month = " << static_cast<const void *>(&month) << std::endl;
    std::cout << "&day = " << static_cast<const void *>(&day) << std::endl;
    
    for (i=0; i<4; i++){
        std::cout << "&wish[" << i << "]" << " = " << static_cast<const void *>(&wish[i]) << std::endl;
    }
    std::cout << "wish as int = " << std::hex << "0x" << *reinterpret_cast<int*>(wish) << std::endl;
    
    STACK_DIR stack_growth_dir = test_stack_direction();
    std::cout << "stack_growth_dir = " << stack_growth_dir << std::endl;
    
    return 0;
}

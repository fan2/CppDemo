//
//  main.cpp
//  WORDSIZE
//
//  Created by faner on 2017/8/15.
//  Copyright © 2017年 zimushan. All rights reserved.
//

#include <iostream>
#include <cstdint>  // C++11
#include <climits>

#if __WORDSIZE==32
#pragma message("__WORDSIZE==32")
#elif __WORDSIZE==64
#pragma message("__WORDSIZE==64")
#endif

// 获取指针宽度（机器字宽）
int GetWordSize()
{
    return sizeof(uintptr_t)*CHAR_BIT;
}

int main(int argc, const char * argv[]) {
    std::cout << "__WORDSIZE ==========" << std::endl;
    std::cout << "WordSize = " << GetWordSize() << std::endl;   // 64
    std::cout << "sizeof(uintptr_t) = " << sizeof(uintptr_t) << std::endl;
    std::cout << "sizeof(ptrdiff_t) = " << sizeof(ptrdiff_t) << std::endl;
    std::cout << "sizeof(size_t) = " << sizeof(size_t) << std::endl;
    std::cout << std::endl;
    
    std::cout << "*_BIT ==========" << std::endl;
    std::cout << "CHAR_BIT = " << CHAR_BIT << std::endl;        // 8
    std::cout << "WORD_BIT = " << WORD_BIT << std::endl;        // 32
    std::cout << "LONG_BIT = " << LONG_BIT << std::endl;        // 32 for 32 bit; 64 for 64 bit
    std::cout << std::endl;
    
    std::cout << "*_MAX ==========" << std::endl;
    std::cout << "UCHAR_MAX = " << UCHAR_MAX << std::endl;      // 1byte
    std::cout << "USHRT_MAX = " << USHRT_MAX << std::endl;      // 2byte
    std::cout << "UINT_MAX = " << UINT_MAX << std::endl;        // 4byte
    std::cout << "ULONG_MAX = " << ULONG_MAX << std::endl;      // 4byte for 32bit; 8byte for 64bit
    std::cout << "ULLONG_MAX = " << ULLONG_MAX << std::endl;    // 8byte
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}

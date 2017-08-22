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
    std::cout << "WordSize = " << GetWordSize() << std::endl;   // 64
    std::cout << "__WORDSIZE = " << __WORDSIZE << std::endl;
    std::cout << std::endl;
    
    std::cout << "========== LONG_BIT ==========" << std::endl;
    std::cout << "CHAR_BIT = " << CHAR_BIT << std::endl;        // 8
    std::cout << "WORD_BIT = " << WORD_BIT << std::endl;        // 32
    std::cout << "LONG_BIT = " << LONG_BIT << std::endl;        // 32 for 32 bit; 64 for 64 bit
    std::cout << std::endl;
    
    std::cout << "========== __SIZEOF_INT__ ==========" << std::endl;
    std::cout << "__SIZEOF_SHORT__ = " << __SIZEOF_SHORT__ << std::endl;
    std::cout << "__SIZEOF_INT__ = " << __SIZEOF_INT__ << std::endl;
    std::cout << "__SIZEOF_LONG__ = " << __SIZEOF_LONG__ << std::endl;
    std::cout << "__SIZEOF_LONG_LONG__ = " << __SIZEOF_LONG_LONG__ << std::endl;
    std::cout << std::endl;
    
    std::cout << "========== __SIZE_TYPE__ ==========" << std::endl;
    std::cout << "sizeof(size_t) = " << sizeof(size_t) << std::endl;
    std::cout << "__SIZEOF_SIZE_T__ = " << __SIZEOF_SIZE_T__ << std::endl;
    std::cout << "__SIZE_WIDTH__ = " << __SIZE_WIDTH__ << std::endl;
    std::cout << std::endl;
    
    std::cout << "========== POINTER, UINTPTR, PTRDIFF ==========" << std::endl;
    std::cout << "__SIZEOF_POINTER__ = " << __SIZEOF_POINTER__ << std::endl;
    std::cout << "__POINTER_WIDTH__ = " << __POINTER_WIDTH__ << std::endl;
    
    std::cout << "sizeof(uintptr_t) = " << sizeof(uintptr_t) << std::endl;
    std::cout << "__INTPTR_WIDTH__ = " << __INTPTR_WIDTH__ << std::endl;
    std::cout << "__UINTPTR_WIDTH__ = " << __UINTPTR_WIDTH__ << std::endl;
    
    std::cout << "sizeof(ptrdiff_t) = " << sizeof(ptrdiff_t) << std::endl;
    std::cout << "__SIZEOF_PTRDIFF_T__ = " << __SIZEOF_PTRDIFF_T__ << std::endl;
    std::cout << "__PTRDIFF_WIDTH__ = " << __PTRDIFF_WIDTH__ << std::endl;
    std::cout << std::endl;
    
    std::cout << "========== __WCHAR_TYPE__ ==========" << std::endl;
    std::cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << std::endl;
    std::cout << "__WCHAR_WIDTH__ = " << __WCHAR_WIDTH__ << std::endl;
    std::cout << std::endl;
    
    std::cout << "========== *_MAX ==========" << std::endl;
    // 1byte
    std::cout << "SCHAR range = [" << SCHAR_MIN << "," << SCHAR_MAX << "]" << std::endl;
    std::cout << "UCHAR range = [" << "0" << "," << UCHAR_MAX << "]" << std::endl;
    // 2byte
    std::cout << "SHRT range = [" << SHRT_MIN << "," << SHRT_MAX << "]" << std::endl;
    std::cout << "USHRT range = [" << "0" << "," << USHRT_MAX << "]" << std::endl;
    // 4byte
    std::cout << "INT range = [" << INT_MIN << "," << INT_MAX << "]" << std::endl;
    std::cout << "UINT range = [" << "0" << "," << UINT_MAX << "]" << std::endl;
    // 4byte for 32bit; 8byte for 64bit
    std::cout << "LONG range = [" << LONG_MIN << "," << LONG_MAX << "]" << std::endl;
    std::cout << "ULONG range = [" << "0" << "," << ULONG_MAX << "]" << std::endl;
    // 8byte
    std::cout << "LLONG range = [" << LLONG_MIN << "," << LLONG_MAX << "]" << std::endl;
    std::cout << "ULLONG range = [" << "0" << "," << ULLONG_MAX << "]" << std::endl;
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}

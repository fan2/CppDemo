//
//  main.cpp
//  BYTE_ORDER
//
//  Created by faner on 2017/8/16.
//  Copyright © 2017年 zimushan. All rights reserved.
//

// [字节串存储](http://blog.csdn.net/phunxm/article/details/5080981)

bool isBigEndian() {
    char bytes[] = {0x12, 0x34};
    return (*((unsigned short*)&bytes) == 0x1234);
    
    unsigned short v = 0x4321;
    return (*((unsigned char*)&v) == 0x43);
}

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import <Foundation/NSByteOrder.h>

// 预编译警告信息将在build report log中输出
#if __DARWIN_BYTE_ORDER == __DARWIN_BIG_ENDIAN
#pragma message("__DARWIN_BIG_ENDIAN")
#elif __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
#pragma message("__DARWIN_LITTLE_ENDIAN")
#endif

#if defined(__BIG_ENDIAN__)
#pragma message("__BIG_ENDIAN__")
#elif defined(__LITTLE_ENDIAN__)
#pragma message("__LITTLE_ENDIAN__")
#endif

BOOL isLittleEndian()
{
    static CFByteOrder bo = CFByteOrderUnknown;
    
    if (bo == CFByteOrderUnknown) { // run only once
        union w
        {
            short a;    // 2 byte
            char b;     // 1 byte
        } c;
        c.a = 1;
        bo = (c.b?CFByteOrderLittleEndian:CFByteOrderBigEndian); // 高位存储低权字节，则为小端
    }
    
    return bo==CFByteOrderLittleEndian;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"isBigEndian = %d", isBigEndian()); // 0
        NSLog(@"isLittleEndian = %d", isLittleEndian()); // 1
        NSLog(@"NSHostByteOrder = %ld", NSHostByteOrder()); // NS_LittleEndian=CFByteOrderLittleEndian=1
    }
    return 0;
}

#else

#include <iostream>

// see CFByteOrder
typedef enum {
    ByteOrderUnknown,
    ByteOrderLittleEndian,
    ByteOrderBigEndian
} ByteOrder;

ByteOrder testByteOrder()
{
    static ByteOrder bo = ByteOrderUnknown;
    
    if (bo == ByteOrderUnknown) { // run only once
        union w
        {
            short a;    // 2 byte
            char b;     // 1 byte
        } c;
        c.a = 1;
        bo = (c.b?ByteOrderLittleEndian:ByteOrderBigEndian); // 高位存储低权字节，则为小端
    }
    
    return bo;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "isBigEndian() = " << isBigEndian() << std::endl;
    std::cout << "testByteOrder() = " << testByteOrder() << std::endl;
    return 0;
}

#endif





//
//  is_derived_from.hpp
//  CppLib
//
//  Created by faner on 2017/8/17.
//  Copyright © 2017年 zimushan. All rights reserved.
//

// std::is_base_of is Defined in header <type_traits>

// [std::is_base_of](http://en.cppreference.com/w/cpp/types/is_base_of)
// [How does `is_base_of` work?](https://stackoverflow.com/questions/2910979/how-does-is-base-of-work)
// [由is_base_of看C++中的SFINAE](http://blog.csdn.net/zhangjun03402/article/details/48626957)

#ifndef is_derived_from_hpp
#define is_derived_from_hpp

// test if Derived is derived from Base or if both are the same non-union class
// if class Derived : class Base, then D is-a B
namespace Utilities {
    // template< class Base, class Derived >
    template <typename D, typename B>
    struct is_derived_from {
        struct yes_type {enum {value = true}; char padding[1];};
        struct no_type {enum {value = false}; int padding[2];};
        static yes_type is_derived_from_test(B*);    // empty function body
        static no_type is_derived_from_test(...);    // empty function body
        enum {value = (sizeof(is_derived_from_test(static_cast<D*>(0))) == sizeof(yes_type))};
    };
};

#endif /* is_derived_from_hpp */

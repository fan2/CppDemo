//
//  main.cpp
//  Utilities
//
//  Created by faner on 2017/8/17.
//  Copyright © 2017年 zimushan. All rights reserved.
//

#include <iostream>
#include <typeinfo>

#include <type_traits>
#include "is_kind_of.hpp"

class A {};
class B : A {};
class C {};
class D : public B {};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // typeid(RTTI)：获取类名
    const std::type_info& tiA = typeid(A);
    const std::type_info& tiB = typeid(B);
    const std::type_info& tiC = typeid(C);
    const std::type_info& tiD = typeid(D);
    
    std::cout << "tiA.name: " << tiA.name() << std::endl;
    std::cout << "tiB.name: " << tiB.name() << std::endl;
    std::cout << "tiC.name: " << tiC.name() << std::endl;
    std::cout << "tiD.name: " << tiD.name() << std::endl;
    D d;
    std::cout << "typeid(d).name: " << typeid(d).name() << std::endl;
    // std::type_info::hash_code since C++11
    // std::type_index since C++11
    
    // std::is_base_of：判断是否是基类
    //  template< class Base, class Derived >
    std::cout << std::boolalpha;
    std::cout << "a2b: " << std::is_base_of<A, B>::value << '\n';
    std::cout << "b2a: " << std::is_base_of<B, A>::value << '\n';
    std::cout << "c2b: " << std::is_base_of<C, B>::value << '\n';
    std::cout << "same type: " << std::is_base_of<C, C>::value << '\n';
    
    // Utilities::is_kind_of：判断是否是继承
    //  template <typename Derived, typename Base>
    //  Semantic Issue: Cannot cast 'B' to its private base class 'A'
    // std::cout << "b2a: " << Utilities::is_kind_of<B, A>::value << '\n';
    std::cout << "D:B = " << Utilities::is_kind_of<D, B>::value << '\n';
    
    return 0;
}


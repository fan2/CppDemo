//
//  main.cpp
//  Utilities
//
//  Created by faner on 2017/8/17.
//  Copyright © 2017年 zimushan. All rights reserved.
//

#include <iostream>

#include <type_traits>
#include "is_derived_from.hpp"

class A {};
class B : A {};
class C {};
class D : public B {};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // std::is_base_of
    //  template< class Base, class Derived >
    std::cout << std::boolalpha;
    std::cout << "a2b: " << std::is_base_of<A, B>::value << '\n';
    std::cout << "b2a: " << std::is_base_of<B, A>::value << '\n';
    std::cout << "c2b: " << std::is_base_of<C, B>::value << '\n';
    std::cout << "same type: " << std::is_base_of<C, C>::value << '\n';
    
    // Utilities::is_derived_from
    //  template <typename Derived, typename Base>
    //  Semantic Issue: Cannot cast 'B' to its private base class 'A'
    // std::cout << "b2a: " << Utilities::is_base_of<B, A>::value << '\n';
    std::cout << "D:B = " << Utilities::is_derived_from<D, B>::value << '\n';
    
    return 0;
}


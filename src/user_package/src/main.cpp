//
// Created by yossi on 6/21/19.
//

#include <iostream>
#include <library_pkg/SimpleLibrary/simple_library.hpp>


int main()
{
    // int i = USING_LIBRARY_PKG;
    std::cout << "user_package main executable  " << std::endl;
    // auto c = SimpleNamespace::SimpleLibrary::foo();
    std::cout << "The answer: " << SimpleNamespace::SimpleLibrary::foo() << std::endl;

    return 0;
}

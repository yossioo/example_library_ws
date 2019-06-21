//
// Created by yossi on 6/21/19.
//


#include <iostream>
#include <SimpleLibrary/simple_library.hpp>


int main (){
    std::cout << "The answer: " << SimpleNamespace::SimpleLibrary::foo()  << std::endl;
    return 0;
}
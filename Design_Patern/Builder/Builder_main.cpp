#include "Builder.hpp"

#include <iostream>

int main ()
{
    // ------------------- 빌더 설정 단 ------------------------
    IBuilder*    builderA = new BuilderA();
    IBuilder*    builderB = new BuilderB();
    Director    director(builderA);
    
    // ------------------- 사용단 ----------------------

    Product*    new_product = director.doPart1Part2Part3();

    std::cout << new_product->getData() << std::endl;
    delete new_product;

    new_product = director.doPart1Part3();
    std::cout << new_product->getData() << std::endl;
    delete new_product;

    new_product = director.doPart2();
    std::cout << new_product->getData() << std::endl;
    delete new_product;
    // ------------------- 빌더 변경 ------------------------

    std::cout << "builder changed" << std::endl;

    director.changeBuilder(builderB);

    new_product = director.doPart1Part2Part3();
    std::cout << new_product->getData() << std::endl;
    delete new_product;

    new_product = director.doPart1Part3();
    std::cout << new_product->getData() << std::endl;
    delete new_product;

    new_product = director.doPart2();
    std::cout << new_product->getData() << std::endl;
    delete new_product;

    delete builderA;
    delete builderB;
}
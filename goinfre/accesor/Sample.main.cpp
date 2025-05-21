#include <iostream>
#include "Sample.class.hpp"

int main(void)
{
    Sample instance;

     if (instance.setFoo(42))
        std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
    else
        std::cerr << "Can not change instance._foo" << std::endl;

    if (instance.setFoo(-42))
        std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
    else
        std::cerr << "Can not change instance._foo" << std::endl;
    return (0);
}
#include <iostream>
#include "Sample.class.hpp"

/*Interieur de la class*/
Sample1::Sample1(void)
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample1::~Sample1(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample1::bar(void) const
{
    std::cout << "Member private function called" << std::endl;
    return ;
}
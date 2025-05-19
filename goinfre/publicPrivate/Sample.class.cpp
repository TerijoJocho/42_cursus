#include <iostream>
#include "Sample.class.hpp"

/*Interieur de la class*/
Sample::Sample(void)
{
    std::cout << "INSIDE" << std::endl;
    std::cout << "Constructor called" << std::endl;
    this->publicFoo = 0;
    std::cout << "this->publicFoo = " << this->publicFoo << std::endl;
    this->_privateFoo = 0;
    std::cout << "this->_privateFoo = " << this->_privateFoo << std::endl;
    this->publicBar();
    this->_privateBar();
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::publicBar(void) const
{
    std::cout << "Member public function called" << std::endl;
    return ;
}

void    Sample::_privateBar(void) const
{
    std::cout << "Member private function called" << std::endl;
    return ;
}
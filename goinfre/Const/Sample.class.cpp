#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(float const f) : pi(f), qd(42)//j'initialise pi  à f !!!
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

//fonction memebre ne modifiera jamais l'instance courante
void    Sample::bar(void) const
{
    //fonctionne pas car fonction const (+ variable const)!!
    //this->pi = 3.15f;
    // this->qd = 0;
    std::cout << "this->pi = " << this->pi << std::endl;
    std::cout << "this->qd = " << this->qd << std::endl;

    return ;
}
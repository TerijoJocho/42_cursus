#include <iostream>
#include "Sample.class.hpp"

/*Interieur de la class*/
Sample::Sample(int v) : _foo(v)
{
    std::cout << "Constructor called" << std::endl;
    std::cout << "_foo = " << this->_foo << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

/*Donne un acces en lecture sur mon attribut
* et renvoie une copie de mon attribut
*/
int    Sample::getFoo(void) const
{
    return (this->_foo);
}

int    Sample::compare(Sample *other) const
{
    if (this->_foo < other->getFoo())
        return (-1);
    else if (this->_foo > other->getFoo())
        return (1);
    return (0);
}
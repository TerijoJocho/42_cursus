#include <iostream>
#include "Sample.class.hpp"


/*On va creer plusieurs instances et regarder combien il y en a(?)*/
void    f0(void)
{
    Sample  instance;//+1

    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
    return ;//-1
}

void    f1(void)
{
    Sample  instance;//+1

    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
    f0();
    return ;//-1
}

int main(void)
{
    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
    f1();
    std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

    return (0);
}
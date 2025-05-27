#include <iostream>
#include "Sample.class.hpp"

/*Exterieur de la class*/
int main(void)
{
    Sample instance;//le code dans le fichier de la class est exec

    std::cout << "OUTSIDE" << std::endl;
    //Dans le public c'est bon
    instance.publicFoo = 42;
    std::cout << "instance.publicFoo = " << instance.publicFoo << std::endl;
    instance.publicBar();
    //Dans le privé non
    //instance._privateFoo = 42;
    //std::cout << "instance._privateFoo = " << instance._privateFoo << std::endl;
    //instance._privateBar();
    return(0);
}

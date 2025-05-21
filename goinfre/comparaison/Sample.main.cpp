#include <iostream>
#include "Sample.class.hpp"


/*comparaison physique et structurelle entre deux class*/
int main(void)
{
    //deux instances qui ont deux adresses memoires differentes(physique)
    //mais la meme structure car le meme contenu
    Sample instance1(42);
    Sample instance2(42);

    if (&instance1 == &instance1)
        std::cout << "instance1 and instance1 are physically equal" << std::endl;
    else
    std::cout << "instance1 and instance1 are not physically equal" << std::endl;

    if (&instance1 == &instance2)
        std::cout << "instance1 and instance2 are physically equal" << std::endl;
    else
    std::cout << "instance1 and instance2 are not physically equal" << std::endl;



    if (instance1.compare(&instance1) == 0)
        std::cout << "instance1 and instance1 are structurally equal" << std::endl;
    else
    std::cout << "instance1 and instance1 are not structurally equal" << std::endl;

    if (instance1.compare(&instance2) == 0)
        std::cout << "instance1 and instance2 are structurally equal" << std::endl;
    else
    std::cout << "instance1 and instance2 are not structurally equal" << std::endl;

    return (0);
}
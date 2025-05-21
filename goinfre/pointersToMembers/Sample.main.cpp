#include <iostream>
#include "Sample.class.hpp"

int main(void)
{
    Sample  instance;
    Sample  *instance_p = &instance;//pointeur sur instance

    int     Sample::*p = NULL;//un poiteur sur un int membre de la classe Sample
    void    (Sample::*f)(void)const;

    //p prend l'adresse d'un entier de la class Sample
    //on ne sait pas encore de quelle instance on recupere l'adresse
    //car on pourrait en avoir plusieurs
    p = &Sample::foo;
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    //nouvelle opérateur ".*"
    //permet de donner une valeur au contenu du pointeur p
    //de l'instance "instance"
    instance.*p = 21;
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance_p->*p = 42;
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    //mon poiteur sur fonction membre
    //va pointer sur la fonction bar de la class Sample
    f = &Sample::bar;
    //appel a la fonction membre directement depuis l'instance "instance"
    (instance.*f)();
    //appel a la fonction membre depuis un poiteur sur l'instance "instance"
    (instance_p->*f)();

    return (0);
}
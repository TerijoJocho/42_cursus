#include <iostream>
#include "Sample.class.hpp"

/*Interieur de la class*/
Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
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

/*Permet a l'utilisateur de modifier la variable privée 
* mais que à une condition
* NB : en cas réel, si l'utilisateur n'a pas reussi a set la variable,
*      il faut renvoyer un message d'erreur ou mettre un message dans un log
*      Par exemple donner un type bool à la fonction pour informer l'utilisateur
*      que la modif a été pris en compte ou pas
*/
bool    Sample::setFoo(int v)
{
    if (v >= 0)
    {
        this->_foo = v;
        return (true);
    }
    return (false);
}
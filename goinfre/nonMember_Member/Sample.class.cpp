#include <iostream>
#include "Sample.class.hpp"

/*Interieur de la class*/

Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
    Sample::_nbInst += 1;
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    Sample::_nbInst -= 1;
    return;
}

//fonction non membre
//dans ce cas on ne peut pas faire appel au pointeur this->
//car il n'y a pas d'instance invisible envoyé en parametre
int    Sample::getNbInst(void)
{
    return (Sample::_nbInst);
}

//attribut non membre ne peut pas etre initialisé dans une instance
//donc on l'initialise ici comme ça 
//oui a l'exterieur de la class meme si c'est un attribut private
int Sample::_nbInst = 0;
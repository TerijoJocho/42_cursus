#include <iostream>
#include "Sample.class.hpp"

int main(void)
{
    Sample2 instance2;
    Sample1 instance1;

    /*
    on remarque que le compilateur nous dit que 
    Sample1 a un constructor et un destructor privée
    malgre le fait qu'on ne l'ai pas precisé
    ET
    on a aucune erreur sur la compilation de Sample2

    => les structures sont public et les class sont privées
    par defaut
    Ainsi, il vaut mieux utiliser les class !!
    */
    return(0);
}
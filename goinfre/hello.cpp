#include <iostream>
#include <unistd.h>
#include <string>

//g++ -std=c++98 -Wall -Wextra -Werror hello.cpp
int main()
{
    // std::cout << "Hello World !";//sortie std sans flush
    // std::cout << "Hello World !" << std::endl; //avec flush de la memoire tampon
    // sleep(5);//pour bloquer le flush automatique du systeme
    // std::cerr << "Wordl Hello ?" << std::endl;//sortie error
    // std::clog << "CACA" << std::endl;//journalisation(?)

    // int i;
    // int j(45);

    // i = 95;
    // std::cout << "i = " << i << std::endl << "j = " << j << std::endl;

    int ageUtilisateur = 0;
    std::string    nomUtilisateur = "vide";

    std::cout << "Quel âge avez-vous ?" << std::endl;
    std::cin >> ageUtilisateur;
    std::cout << "Et votre nom ?" << std::endl;
    std::cin >> nomUtilisateur;
    std::cout << "Vous avez " << ageUtilisateur << " ans !" << "Vous vous appelez " << nomUtilisateur << std::endl;
    return (0);
}
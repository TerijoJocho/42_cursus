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

    // int ageUtilisateur(0);
    // std::string    nomUtilisateur = "vide";
	// double piValeur = 0;
    // std::cout << "Quel est votre nom et prenom ?" << std::endl;
    // // std::cin >> nomUtilisateur;
	// getline(std::cin, nomUtilisateur);//permet de prendre toute la ligne dans le buffer
    // std::cout << "Et votre age ?" << std::endl;
    // std::cin >> ageUtilisateur;
	// std::cout << "Quelle est la valeur de pi??" << std::endl;
	// std::cin >> piValeur;
	// std::cout << "Vous vous appelez " << nomUtilisateur << std::endl;
    // std::cout << "Vous avez " << ageUtilisateur << " ans !" << std::endl;
	// std::cout << "Vous pensez que la valeur de pi est: " << piValeur << std::endl;

	// std::cout << "Quelle est la valeur de pi??" << std::endl;
	// std::cin >> piValeur;
	// std::cin.ignore();//ignore l'input de l'utilisateur jusqu'au '\n'
	// std::cout << "Quel est votre nom et prenom ?" << std::endl;
	// getline(std::cin, nomUtilisateur);
    // std::cout << "Et votre age ?" << std::endl;
    // std::cin >> ageUtilisateur;
	// std::cout << "Vous vous appelez " << nomUtilisateur << std::endl;
    // std::cout << "Vous avez " << ageUtilisateur << " ans !" << std::endl;
	// std::cout << "Vous pensez que la valeur de pi est: " << piValeur << std::endl;

	int	a = 0, b = 0;

	std::cout << "Donnez la valeur de a" << std::endl;
	std::cin >> a;
	std::cin.ignore();
	std::cout << "Donnez la valeur de b" << std::endl;
	std::cin >> b;
	std::cin.ignore();
	std::cout << "La resultat de l'addition est: " << a + b << std::endl;
	std::cout << "La resultat de la soustraction est: " << a - b << std::endl;
	std::cout << "La resultat de la multiplication est: " << a * b << std::endl;
	std::cout << "La resultat de la division est: " << a / b << std::endl;
    return (0);
}

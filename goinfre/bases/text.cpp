#include <iostream>
#include <string>

void printMessage(std::string str)
{
    std::cout << str << std::endl;
    return ;
}

//on prefere donner lar reference des param pour ne pas creer de copies des strings
//de plus on ajoute const car a la base lorsqu'on donne la reference c'est pour modifier
//la valeur d'une variable, cependant ici on ne veut pas la modifier
//donc on ajoute const juste devant 
std::string concatenate(const std::string &a, std::string b = "Non")
{
    return (a + b);
}

int main(void)
{
    std::string res;

    printMessage("caca");
    printMessage("53");
    res = concatenate("Mais");
    printMessage(res);
    res = concatenate("Mais", "Oui");
    printMessage(res);
    return(0);
}
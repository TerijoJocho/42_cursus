#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter ::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string const str)
{
    /*if str is a char*/
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        char c = str[0];

        if (!std::isprint(c))
            std::cout << "char: not displayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return ;
    }

    /*parse la str en nombre*/
    char*   end;    
    double  d = std::strtod(str.c_str(), &end);

    if (end == str.c_str()) //aucun nombre lu
    {
        std::cerr << "Conversion failed." << std::endl;
        return ;
    }
    if (*end != '\0') //nombre lu mais caracteres apres lui
    {
        if (*end == 'f' && *(end + 1) == '\0') //si .f carre
        {
        }
        else //si autre chose ca degage
        {
            std::cout << "Conversion failed." << std::endl;
            return ;
        }
    }

    /*print les valeurs convertie*/
    if (d < 0 || d > 127 || !std::isnan(d)) // si d peut pas etre un char
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d))) //si le la conversion en char n'est pas imprimable
        std::cout << "char: not displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(d) << std::endl;

    if (d < static_cast<double>(std::numeric_limits<int>::min()) || // on compare les limits int en double
        d > static_cast<double>(std::numeric_limits<int>::max()) || // pour ne pas avoir d'overflow
        !std::isnan(d))                                                     // on verifie si c'est un NaN
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d);
    if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d)) // verifie si le nombre n'est pas un nan, n'est pas en notation scientifique et est un entier
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(d);
    if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
        std::cout << ".0";
    std::cout << std::endl;
}

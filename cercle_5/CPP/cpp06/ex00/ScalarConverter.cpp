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
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string const str)
{
	char	c;
	char	*end;
	double	d;

	/*if str is a char*/
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		c = str[0];
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
	d = std::strtod(str.c_str(), &end);
	if (end == str.c_str()) // aucun nombre lu
	{
		std::cerr << "Conversion failed." << std::endl;
		return ;
	}
	if (*end != '\0') // nombre lu mais caracteres apres lui
	{
		if (*end == 'f' && *(end + 1) == '\0') // si .f carre
		{
		}
		else // si autre chose ca degage
		{
			std::cout << "Conversion failed." << std::endl;
			return ;
		}
	}

	/*print les valeurs convertie*/
	// si d peut pas etre un char
	if (d < 0 || d > 127 || !std::isnan(d))
		std::cout << "char: impossible" << std::endl;
	// si le la conversion en char n'est pas imprimable
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;

	// on compare les limits int en double
	// pour ne pas avoir d'overflow
	// on verifie si c'est un NaN
	if (d < static_cast<double>(std::numeric_limits<int>::min())
		|| d > static_cast<double>(std::numeric_limits<int>::max())
		|| !std::isnan(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d);

	// verifie si le nombre n'est pas un nan,
	//n'est pas en notation scientifique et est un entier
	if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	//de meme pour les double
	std::cout << "double: " << static_cast<double>(d);
	if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
		std::cout << ".0";
	std::cout << std::endl;
}

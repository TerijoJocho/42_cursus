#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

// # pragma once
# include <cstdlib>
# include <iostream>
# include <string>
#include <cmath>
#include <limits>

class ScalarConverter
{
  public:
	~ScalarConverter();

	static void convert(std::string const str);

  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
};

#endif

#include "ScalarConverter.hpp"

int main(void)
{
    {
        std::cout << "---CHAR LITERALS---" << std::endl;
        std::string str;

        str = "a";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "Z";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "0";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "\t";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "127";
        ScalarConverter::convert(str);
    }
    {
        std::cout << "\n\n---INT SCALARS---" << std::endl;
        std::string str;

        str = "0";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "42";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-42";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "2147483647";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-2147483648";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "2147483648";
        ScalarConverter::convert(str);
    }
    {
        std::cout << "\n\n---FLOAT SCALARS---" << std::endl;
        std::string str;

        str = "0";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "42.42f";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-42.42f";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "inff";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-inff";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "1e10f";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "nanf";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "1e10fff";
        ScalarConverter::convert(str);
    }
    {
        std::cout << "\n\n---DOUBLE SCALARS---" << std::endl;
        std::string str;

        str = "0.0";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "42.42";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-42.42";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "inf";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-inf";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "1e100";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "nan";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "1.0.0";
        ScalarConverter::convert(str);
        
    }
    {
        std::cout << "\n\n---DOESN'T WORK---" << std::endl;
        std::string str;

        str = "abc";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "4.2fert";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "nanff";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "++42";
        ScalarConverter::convert(str);
        std::cout << "\n";

        str = "-42f42";
        ScalarConverter::convert(str);
    }

    return 0;
}
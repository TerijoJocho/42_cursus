# include "phoneBookClass.hpp"

bool	isAlphaPlusWhitetSpace(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] < 33 && str[i] > 126))
			return (false);
	}
	return (true);
}

bool	isAlphaPlus(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] < 33 && str[i] > 126) || str[i] == ' ' || str[i] == '\t')
			return (false);
	}
	return (true);
}

bool	isAlphaSpace(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]) && str[i] != ' ')
			return (false);
	}
	return (true);
}

bool	isAlpha(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool	isDigit(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isContact(char c)
{
	for (int i = 0; i < 8; i++)
	{
		if (c < 49 || c > 56)
			return (false);
	}
	return (true);
}

int	strToInt(std::string str)
{
	int	number;

	std::istringstream iss(str);
	iss >> number;
	return (number);
}

bool	isInContact(std::string &input, int &contactNumber)
{
	for (int i = 0; i < contactNumber; i++)
	{
		if (strToInt(input) == i + 1)
			return (true);
	}
	return (false);
}

bool	checkSearchInput(std::string input, int contactNumber)
{
	if (input.empty())
		return (false);
	else if (input.length() > 1 || !isContact(input[0])
		|| !isDigit(input) || !isInContact(input, contactNumber))
	{
		std::cout << "Please put a valid contact index...\n";
		return (false);
	}
	return (true);
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

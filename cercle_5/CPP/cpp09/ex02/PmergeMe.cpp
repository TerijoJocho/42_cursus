#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string &input) : _input(input)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

void	PmergeMe::processInput()
{
	if (!_isValidInput())
		throw std::invalid_argument("Input mustcontain only positive integers.");

}

bool	PmergeMe::_isValidInput() const
{
	// for(size_t i = 0; i < _input.size(); i++)
	// {
	// 	if (!isdigit(_input[i]))
	// }

	return true;
}

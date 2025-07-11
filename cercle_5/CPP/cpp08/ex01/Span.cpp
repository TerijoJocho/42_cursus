#include "Span.hpp"
#include <vector>

Span::Span(int n) : _N(n)
{
	std::srand(std::time(0));
}

Span::~Span()
{
}

Span::Span(const Span &other) : _N(other.getN())
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		this->_N = other.getN();
	return *this;
}

unsigned int	Span::getN() const
{
	return this->_N;
}

void	Span::addNumbers(unsigned int nb)
{
	// std::cout << "test_size: " << this->_dq.size() << std::endl;
	if (this->_dq.size() >= this->_N)
		throw std::length_error("Container is full");
	this->_dq.push_back(nb);
	// std::cout << "test_containing: " << this->_dq.back() << std::endl;
}

void	Span::addLoop()
{
	for (unsigned int i = 0; i < this->getN(); i++)
	{
		unsigned int r = std::rand();
		try
		{
			this->_dq.push_back(r);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Lenght error: " << e.what() << '\n';
		}
	}
}

/*Pour verif*/
// void	Span::addLoop()
// {
// 	std::vector<unsigned int>	v;
// 	for (unsigned int i = 0; i < this->getN(); i++)
// 		v.push_back(i);

// 	std::random_shuffle(v.begin(), v.end());

// 	for (unsigned int i = 0; i < this->getN(); i++)
// 		this->_dq.push_back(v[i]);
// }

unsigned int Span::shortestSpan() const
{
	if (this->_N <= 1)
		throw std::logic_error("There are not enough numbers.");

	std::deque<unsigned int>	cpy;
	copy(this->_dq.begin(), this->_dq.end(), back_inserter(cpy));

	try
	{
		sort(cpy.begin(), cpy.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Try to sort but: " << e.what() << '\n';
	}

	unsigned int	min = cpy[1] - cpy[0];

	for (size_t i = 1; i < cpy.size() - 1; i++)
	{
		unsigned int	diff = cpy[i + 1] - cpy[i];
		if (min > diff)
			min = diff;
	}

	return min;
}

unsigned int Span::longestSpan() const
{
	if (this->_N <= 1)
		throw std::logic_error("There are not enough numbers.");

	unsigned int	max = *max_element(this->_dq.begin(), this->_dq.end());
	unsigned int	min = *min_element(this->_dq.begin(), this->_dq.end());

	return (max - min);
}

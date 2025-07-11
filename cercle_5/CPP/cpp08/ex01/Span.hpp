#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Span
{
  public:
	Span(int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	unsigned int		getN() const;
	void				addNumbers(unsigned int nb); //add a single number to the Span
	void				addLoop();
	unsigned int		shortestSpan() const;
	unsigned int		longestSpan() const;


  private:
	unsigned int	_N;
	std::deque<int>		_dq;

};

#endif

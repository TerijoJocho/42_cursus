#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <stdexcept>
#include <queue>
#include <sstream>
#include <string>

class PmergeMe
{
  public:
	PmergeMe(std::string &input);
	~PmergeMe();

	void	processInput();

  private:
	const std::string _input;
	std::queue<int>	_inputQ;

	bool	_isValidInput() const;

	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
};

#endif

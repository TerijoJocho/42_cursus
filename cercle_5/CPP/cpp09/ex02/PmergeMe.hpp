#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <queue>
# include <sstream>
# include <stdexcept>
# include <string>
# include <vector>
#include <algorithm>

class PmergeMe
{
  public:
	PmergeMe();
	~PmergeMe();

	void processInput();
	void pushIntoQueue(int x);

  private:
	std::queue<int> _inputQ;
	std::list<int> _lMin;
	std::list<int> _lMax;
	std::vector<int> _vMin;
	std::vector<int> _vMax;
	int				_leftover;

	void displayQueue();
	void createVandL();
	void sortAndMergeVandL();

	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
};

#endif

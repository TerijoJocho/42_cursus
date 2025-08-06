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
#include <ctime>
#include <iomanip>

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
	clock_t	_endVector;
	clock_t	_endList;

	void displayQueue();
	void createVandL();
	std::vector<int> getOrder(size_t) const;
	void sortAndMergeVandL();

	static int jacobshtal[];

	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
};

#endif

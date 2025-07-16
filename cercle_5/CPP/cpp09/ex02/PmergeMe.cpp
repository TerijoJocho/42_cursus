#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
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
	std::cout << "Before: "; this->displayQueue(); std::cout << std::endl;

	//start time
	clock_t	startVector = clock();
	clock_t	startList = clock();
	//create min and max sequence
	this->_leftover = -1;
	this->createVandL();
	//sort max sequence
	this->sortAndMergeVandL();


	/*test-----------------------------------------------------------------------*/
	// std::cout << "\nvMax total: ";
	// for (std::vector<int>::iterator	it = _vMax.begin(); it != _vMax.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "lMax total: ";
	// for (std::list<int>::iterator	it = _lMax.begin(); it != _lMax.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// /*--------------------------------------------------------------------------*/
	while (!_inputQ.empty())
	{
		_inputQ.pop();
	}
	for (std::vector<int>::iterator	it = _vMax.begin(); it != _vMax.end(); ++it)
	{
		_inputQ.push(*it);
	}
	std::cout << "After: "; this->displayQueue(); std::cout << std::endl;
	double	timeSpanVector = static_cast<double>(this->_endVector - startVector) / CLOCKS_PER_SEC * 1e6;
	double	timeSpanList = static_cast<double>(this->_endList - startList) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of " << _inputQ.size() << " elements with std::vector<int> : "; std::cout << std::fixed << std::setprecision(3) << timeSpanVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _inputQ.size() << " elements with std::list<int> : "; ; std::cout << std::fixed << std::setprecision(3) << timeSpanList<< " us" << std::endl;
}

void	PmergeMe::createVandL()
{
	while (_inputQ.size() >= 2)
	{
		int j = _inputQ.front(); _inputQ.pop();
		int k = _inputQ.front(); _inputQ.pop();

		if (j <= k)
		{
			_lMin.push_back(j); _lMax.push_back(k);

			_vMin.push_back(j); _vMax.push_back(k);
		}
		else
		{
			_lMin.push_back(k); _lMax.push_back(j);
			_vMin.push_back(k); _vMax.push_back(j);
		}
	}

	if (!_inputQ.empty())
		this->_leftover = _inputQ.front();

	// // /*test--------------------------------------------------------------*/
	// std::cout << "\nvMax: ";
	// for (size_t i = 0; i < _vMax.size(); ++i)
	// 	std::cout << _vMax[i] << " ";
	// std::cout << std::endl;
	// std::cout << "vMin: ";
	// for (size_t i = 0; i < _vMin.size(); ++i)
	// 	std::cout << _vMin[i] << " ";
	// std::cout << std::endl;

	// std::cout << "\nlMax: ";
	// for (std::list<int>::iterator	it = _lMax.begin(); it != _lMax.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "lMin: ";
	// for (std::list<int>::iterator	it = _lMin.begin(); it != _lMin.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// // /*----------------------------------------------------------------*/
}

void	PmergeMe::sortAndMergeVandL()
{
	_lMax.sort();
	std::sort(_vMax.begin(), _vMax.end());

	// /*test--------------------------------------------------------------*/
	// std::cout << "\nvMax sorted: ";
	// for (std::vector<int>::iterator	it = _vMax.begin(); it != _vMax.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	// std::cout << "lMax sorte: ";
	// for (std::list<int>::iterator	it = _lMax.begin(); it != _lMax.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "\nlMin not sorted: ";
	// for (std::list<int>::iterator	it = _lMin.begin(); it != _lMin.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "vMin not sorted: ";
	// for (size_t i = 0; i < _vMin.size(); ++i)
	// 	std::cout << _vMin[i] << " ";
	// std::cout << std::endl;
	// /*----------------------------------------------------------------*/

	for (size_t i = 0; i < _vMin.size(); ++i)
	{
		std::vector<int>::iterator lowVector = std::lower_bound(_vMax.begin(), _vMax.end(), _vMin[i]);
		_vMax.insert(lowVector, _vMin[i]);
	}
	if (this->_leftover == -1)
		_endVector = clock();

	for (std::list<int>::iterator itMin = _lMin.begin(); itMin != _lMin.end(); itMin++)
	{
		std::list<int>::iterator pos = _lMax.begin();
		while(pos != _lMax.end() && *pos < *itMin)
			pos++;
		_lMax.insert(pos, *itMin);
	}
	if (this->_leftover == -1)
		_endList = clock();

	if (this->_leftover != -1)
	{
		std::vector<int>::iterator lowVector = std::lower_bound(_vMax.begin(), _vMax.end(), this->_leftover);
		_vMax.insert(lowVector, this->_leftover);
		_endVector = clock();

		std::list<int>::iterator pos = _lMax.begin();
		while(pos != _lMax.end() && *pos < this->_leftover)
			pos++;
		_lMax.insert(pos, this->_leftover);
		_endList = clock();
	}
}

void	PmergeMe::pushIntoQueue(int x)
{
	this->_inputQ.push(x);
}

void	PmergeMe::displayQueue()
{
	std::queue<int>	copy(_inputQ);
	while (!copy.empty())
	{
		std::cout << copy.front() << " ";
		copy.pop();
	}
}

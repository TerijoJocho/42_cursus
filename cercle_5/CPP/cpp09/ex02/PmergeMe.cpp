#include "PmergeMe.hpp"

int g_comp = 0;

bool	comp(int i, int j)
{
	g_comp++;
	return (i < j);
}

int PmergeMe::jacobshtal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

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
	if (this->_inputQ.size() == 1)
		throw std::logic_error("There is only one element, can not process.");
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

	if (!isSorted(_vMax.begin(), _vMax.end()))
		throw std::runtime_error("Vector is not sorted.");
	if (!isSorted(_lMax.begin(), _lMax.end()))
		throw std::runtime_error("List is not sorted.");

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
	std::cout << "\nTime to process a range of " << _inputQ.size() << " elements with std::vector<int> : "; std::cout << std::fixed << std::setprecision(3) << timeSpanVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _inputQ.size() << " elements with std::list<int> : "; ; std::cout << std::fixed << std::setprecision(3) << timeSpanList<< " us" << std::endl;
	std::cout << "\nNumber of comparaison with Ford-Johnson: " << g_comp << std::endl;
	g_comp = 0;
	std::sort(_forComp.begin(), _forComp.end(), comp);
	std::cout << "Number of comparaison with sort: " << g_comp << std::endl;
}

void	PmergeMe::createVandL()
{
	while (_inputQ.size() >= 2)
	{
		int j = _inputQ.front(); this->_forComp.push_back(j); _inputQ.pop();
		int k = _inputQ.front(); this->_forComp.push_back(k); _inputQ.pop();

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

std::vector<int>	PmergeMe::getOrder(size_t nb) const
{
	std::vector<int>	v;
	if (nb == 0)
		return v;
	if (nb == 1)
	{
		v.push_back(0);
		return v;
	}
	if (nb > 1)
	{
		v.push_back(0);
		v.push_back(1);
	}
	for (size_t i = 2; i < nb; i++)
	{
		// std::cout << "i: " << i << std::endl;
		// std::cout << "nb: " << nb << std::endl;

		//nb = 8
		size_t actual = jacobshtal[i]; //i = 4 et jb = 11
		// std::cout << "actual: " << actual << std::endl;

		size_t before = jacobshtal[i - 1]; // i = 3 et jb = 5
		// std::cout << "before: " << before << std::endl;

		if (actual > nb)
		{
			before++;
			for (; before < nb; before++)
			{
				v.push_back(before);
				// std::cout << "before in for()_2: " << before << std::endl;
			}
			break ;
		}
		else
		{
			v.push_back(actual);
			before++;
			for (; before < actual; before++)
			{
				v.push_back(before);
				// std::cout << "before in for(): " << before << std::endl;
			}
		}
	}

	/*test*/
	// std::cout << "\nTEST" << std::endl;
	// for (size_t i = 0; i < v.size(); i++)
	// {
	// 	std::cout << v[i] << std::endl;
	// }
	/*----*/
	return v;
}

void	PmergeMe::sortAndMergeVandL()
{
	_lMax.sort();
	std::sort(_vMax.begin(), _vMax.end(), comp);
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

	std::vector<int> order = this->getOrder(this->_vMin.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		std::vector<int>::iterator lowVector = std::lower_bound(_vMax.begin(), _vMax.end(), _vMin[order[i]], comp);
		_vMax.insert(lowVector, _vMin[order[i]]);
	}
	if (this->_leftover == -1)
		_endVector = clock();


	for (size_t i = 0; i < order.size(); ++i)
	{
		std::list<int>::iterator itMin = _lMin.begin();
		std::advance(itMin, order[i]);
		std::list<int>::iterator pos = _lMax.begin();
		while(pos != _lMax.end() && *pos < *itMin)
			pos++;
		_lMax.insert(pos, *itMin);
	}
	if (this->_leftover == -1)
		_endList = clock();

	if (this->_leftover != -1)
	{
		std::vector<int>::iterator lowVector = std::lower_bound(_vMax.begin(), _vMax.end(), this->_leftover, comp);
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

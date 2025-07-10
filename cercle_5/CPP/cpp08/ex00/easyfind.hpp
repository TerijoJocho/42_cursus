#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T & container, int toFind)
{
	typename T::iterator	it = find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::out_of_range("Not found");
	return it;
}


#endif

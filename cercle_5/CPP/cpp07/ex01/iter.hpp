#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T> void iter(T *array, size_t arrayLenght, void (*f)(T const &))
{
	for (size_t i = 0; i < arrayLenght; i++)
	{
		f(array[i]);
	}
	return ;
}

#endif

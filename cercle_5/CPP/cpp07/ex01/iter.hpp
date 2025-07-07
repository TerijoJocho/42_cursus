#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F> void iter(T *array, size_t arrayLenght, F f)
{
	for (size_t i = 0; i < arrayLenght; i++)
	{
		f(array[i]);
	}
}

#endif

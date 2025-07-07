#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->array = T new[];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = T new[n];
}

template <typename T>
Array<T>::~Array()
{
	delete this->array;
}

// template <typename T>
// Array<T>::Array(const Array &other)
// {

// }

// template <typename T>
// Array<T> &Array<T>::operator=(const Array &other)
// {

// }


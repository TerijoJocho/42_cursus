#include "Array.hpp"

template <typename T> Array<T>::Array() : _size(0)
{
	this->_array = new T[this->_size];
}

template <typename T> Array<T>::Array(unsigned int n) : _size(n)
{
	this->_array = new T[this->_size];
}

template <typename T> Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T> Array<T>::Array(const Array &other)
{
	this->_size = other.size();
	this->_array = new T[this->_size];

	for (size_t i = 0; i < other.size(); i++)
	{
		this->_array[i] = other._array[i];
	}
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);

	delete[] this->_array;

	this->_size = other.size();
	this->_array = new T[this->_size];

	for (size_t i = 0; i < this->_size; i++)
	{
		this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T> T& Array<T>::operator[](unsigned int i)
{
	// std::cout<< "i= " << i << ", size= " << this->_size << std::endl;
	if (i >= this->size())
		throw std::out_of_range("Index out of range");

	return this->_array[i];
}

template <typename T> const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= this->size())
		throw std::out_of_range("Index out of range");

	return this->_array[i];
}

template <typename T> size_t Array<T>::size() const
{
	return (this->_size);
}

#ifndef ARRAY_HPP
# define ARRAY_HPP

# pragma once
#include <iostream>
#include <exception>

template <typename T> class Array
{
  public:
	Array();               // creates empty array
	Array(unsigned int n); // creates array of n elements
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T& operator[](unsigned int i); //operator to access array[i]
	const T& operator[](unsigned int i) const; //operator to access array[i] in reading only

	size_t	size() const; //getter of _size

  private:
	T *_array;
	size_t _size;
};

#include "Array.tpp"

#endif

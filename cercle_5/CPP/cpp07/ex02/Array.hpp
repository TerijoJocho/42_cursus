#ifndef ARRAY_HPP
# define ARRAY_HPP

# pragma once

template <typename T> class Array
{
  public:
	Array();               // creates empty array
	Array(unsigned int n); // creates array of n elements
	// Array(const Array &other);
	// Array &operator=(const Array &other);
	~Array();

  private:
	T *array;
};

template <typename T> void print(const T &x)
{
	std::cout << x << std::endl;
}

#endif

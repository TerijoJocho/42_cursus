#ifndef BASE_HPP
# define BASE_HPP

# pragma once
#include <iostream>

class Base
{
  public:
	virtual ~Base();

	Base* generator(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif

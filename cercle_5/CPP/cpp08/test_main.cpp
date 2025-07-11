// #include "easyfind.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <iterator>

int main()
{
	{
		std::cout << "---VECTOR---" << std::endl;

		std::vector<int>	v(1, 3);

		std::cout << "Vector size: " << v.size() << std::endl;
		try
		{
			std::cout << "vector.at(0):" << v.at(0) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "vector.at(1):" << v.at(1) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Inserting '5' at the back" << std::endl;
		v.push_back(5);
		try
		{
			std::cout << "vector.at(1):" << v.at(1) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Inserting '654' at the begining" << std::endl;
		v.insert(v.begin(), 654);
		try
		{
			std::cout << "vector.at(0):" << v.at(0) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Then vector is : ";
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Deleting last element" << std::endl;
		v.pop_back();
		std::cout << "Then vector is : ";
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Deleting the '3'" << std::endl;
		v.erase(find(v.begin(), v.end(), 3));
		std::cout << "Then vector is : ";
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << "Vector size: " << v.size() << std::endl;
		std::cout << "If we are searching an element that exist: 654" << std::endl;
		auto it = find(v.begin(), v.end(), 654);
		if (it != v.end())
			std::cout << "654 was found at: " << distance(v.begin(), it) << std::endl;
		else
			std::cout << "654 was not found inside vector" << std::endl;
		std::cout << "If we are searching an element that doesn't exist: 74" << std::endl;
		it = find(v.begin(), v.end(), 74);
		if (it != v.end())
			std::cout << "74 was found at: " << distance(v.begin(), it) << std::endl;
		else
			std::cout << "74 was not found inside vector" << std::endl;
	}
	{
		std::cout << "\n\n---LIST---" << std::endl;
		std::list<std::string>	l = {"Hello", ", ", "World !"};

		std::cout << "List is : ";
		std::list<std::string>::iterator	it = l.begin();
		for (; it != l.end() ; ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Inserting an element at the end" << std::endl;
		l.push_back(" ! !");
		std::cout << "List is : ";
		it = l.begin();
		for (; it != l.end() ; ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Inserting an element at the begining" << std::endl;
		l.push_front("Daryl: ");
		std::cout << "List is : ";
		it = l.begin();
		for (; it != l.end() ; ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Inserting an element at the position 2" << std::endl;
		it = l.begin();
		advance(it, 2);
		l.insert(it, " I am talking ");
		std::cout << "List is : ";
		it = l.begin();
		for (; it != l.end() ; ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "This character is annoying: " << *next(l.begin(), 3) << std::endl;
		std::cout<< "Let's change it" << std::endl;
		it = l.begin();
		advance(it, 3);
		*it = "to MY";
		std::cout << "List is : ";
		it = l.begin();
		for (; it != l.end() ; ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout<< "Deleting an element" << std::endl;
		it = find(l.begin(), l.end(), "Hello");
		if (it != l.end())
			l.erase(it);
		it = l.begin();
		for (; it != l.end() ; ++it)
		{
			std::cout << *it << " ";
		}
	}

	return 0;
}

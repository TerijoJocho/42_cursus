#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main(void)
{
    {
        std::cout << "---MutantStack main---" << std::endl;

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << "The top of the stack is: " << mstack.top() << std::endl;

        mstack.pop();
        std::cout << "The size of the stack is: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Like a container, we can access any element of the stack with iterator:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    {
        std::cout << "---List container main---" << std::endl;

        std::list<int> l;

        l.push_back(5);
        l.push_back(17);
        std::cout << "The top of the list is: " << l.back() << std::endl;

        l.pop_back();
        std::cout << "The size of the list is: " << l.size() << std::endl;

        l.push_back(3);
        l.push_back(5);
        l.push_back(737);
        l.push_back(0);

        std::cout << "Of course, list is a container, so we can use its iterator:" << std::endl;
        std::list<int>::iterator it = l.begin();
        std::list<int>::iterator ite = l.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}
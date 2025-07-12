#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

/*class template derivée de stack*/
template <typename T>
class MutantStack : public std::stack<T> //adaptateur de container, donc pas de begin ni end 
{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        /*on creer un alias "iterator" pour le type iterator du conteneur sous-jacent 'c' -> deque*/
        //definition d'un alias avec typedef
        //typename pour assurer au compilateur que "iterator" est un type et pas un membre statique de la class
        typedef typename std::stack<T>::container_type::iterator        iterator;
        typedef typename std::stack<T>::container_type::const_iterator  const_iterator;

        /*fonction membres*/
        iterator begin();

        iterator end();

        const_iterator begin() const;

        const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
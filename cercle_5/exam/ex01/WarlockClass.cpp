#include "WarlockClass.hpp"

Warlock::Warlock(std::string name, std::string title) : 
    _name(name), _title(title)
{
    for(int i = 0; i < 5; i++)
    {
        this->book[i] = NULL;
    }
    std::cout << this->getName() << ": This look like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    for(int i = 0; i < 5; i++)
    {
        delete this->book[i];
    }
    std::cout << this->getName() << ": My job here is done!" << std::endl;
}

Warlock::Warlock(Warlock const &other)
{
    (void)other;
    return ;
}

Warlock &Warlock::operator=(Warlock const &other)
{
    (void)other;
    return (*this);
}

std::string const &Warlock::getName() const
{
    return (this->_name);
}

std::string const &Warlock::getTitle() const
{
    return (this->_title);
}

void    Warlock::setTitle(std::string const &title)
{
    this->_title = title;
}

void    Warlock::introduce() const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void    Warlock::learnSpell(ASpell* spell)
{
    for(int i = 0; i < 5; i++)
    {
        if (!this->book[i])
        {
            this->book[i] = spell->clone();
            return ;
        }
    }
}
        
void    Warlock::forgetSpell(std::string const spell)
{
    for(int i = 0; i < 5; i++)
    {
        if (this->book[i] && this->book[i]->getName() == spell)
        {
            delete this->book[i];
            this->book[i] = NULL;  
            return ;  
        }
    }
}

void    Warlock::launchSpell(std::string const spell, const ATarget& target)
{
    for(int i = 0; i < 5; i++)
    {
        if (this->book[i] && this->book[i]->getName() == spell)
        {
            this->book[i]->lauch(target);    
            return ;
        }
    }
}
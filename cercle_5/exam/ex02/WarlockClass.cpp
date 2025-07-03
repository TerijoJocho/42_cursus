#include "WarlockClass.hpp"

Warlock::Warlock(std::string name, std::string title) : 
    _name(name), _title(title)
{
    std::cout << this->getName() << ": This look like another boring day." << std::endl;
}

Warlock::~Warlock()
{
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
    if (spell)
        this->_book.learnSpell(spell);
}
        
void    Warlock::forgetSpell(std::string const &spell)
{
    this->_book.forgetSpell(spell);
}

void    Warlock::launchSpell(std::string const &spell, const ATarget& target)
{
    ASpell* Spell = this->_book.createSpell(spell);
    
    if (Spell != NULL)
    {
        Spell->lauch(target);
        delete Spell;
    }
}
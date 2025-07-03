#include "SpellBook.hpp"

SpellBook::SpellBook()
{
    for(int i = 0; i < 3; i++)
    {
        this->spellBook[i] = NULL;
    }
}

SpellBook::~SpellBook()
{
    for(int i = 0; i < 3; i++)
    {
        delete this->spellBook[i];
    }
}

SpellBook::SpellBook(SpellBook const &other)
{
    (void)other;
    return ;
}

SpellBook &SpellBook::operator=(SpellBook const &other)
{
    (void)other;
    return (*this);
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (!spell)
        return ;
    for(int i = 0; i < 3; i++)
    {
        if (!this->spellBook[i])
        {
            this->spellBook[i] = spell->clone();
            return ;
        }
    }
}

void SpellBook::forgetSpell(std::string const &spell)
{
    for(int i = 0; i < 3; i++)
    {
        if (this->spellBook[i]->getName() == spell)
        {
            delete this->spellBook[i];
            this->spellBook[i] = NULL;
            return ;
        }
    }
}
        
ASpell* SpellBook::createSpell(std::string const &spell)
{
    for(int i = 0; i < 3; i++)
    {
        if (this->spellBook[i]->getName() == spell)
        {
            return (this->spellBook[i]->clone());
        }
    }
    return (NULL);
}
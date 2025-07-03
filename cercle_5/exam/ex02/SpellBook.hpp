#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class SpellBook
{
    private:
        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);

        ASpell* spellBook[3];
    
    public:
        SpellBook();
        ~SpellBook();
       
        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);

};

#endif
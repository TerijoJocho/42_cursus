#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        ASpell* book[5];

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
    
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
       
        std::string const &getName() const;
        std::string const &getTitle() const;
        
        void    setTitle(std::string const &title);

        void    introduce() const;

        void    learnSpell(ASpell* spell);
        void    forgetSpell(std::string const spell);
        void    launchSpell(std::string const spell, const ATarget& target);
};

#endif
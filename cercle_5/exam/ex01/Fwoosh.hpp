#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();

        ASpell* clone() const;
};

#endif
#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        ~Polymorph();

        ASpell* clone() const;
};

#endif
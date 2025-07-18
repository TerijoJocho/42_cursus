#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        ~Fireball();

        ASpell* clone() const;
};

#endif
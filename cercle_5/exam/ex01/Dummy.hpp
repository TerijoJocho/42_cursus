#ifndef DUMMY_HPP
#define DUMMY_HPP

#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        ~Dummy();

        ATarget* clone() const;
};

#endif
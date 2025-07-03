#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#pragma once
#include <iostream>
#include "ATarget.hpp"

class TargetGenerator
{
    private:
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);

        ATarget* _types[3];
    
    public:
        TargetGenerator();
        ~TargetGenerator();

        void    learnTargetType(ATarget*);
        void    forgetTargetType(std::string const &);
        ATarget*    createTarget(std::string const &);
};

#endif
#ifndef ATARGET_HPP
#define ATARGET_HPP

#pragma once
#include <iostream>
#include <string>
class ASpell;

class ATarget
{
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget(const ATarget& other);
        ATarget &operator=(const ATarget& other);

        const std::string& getType() const;

        virtual ATarget* clone() const = 0;

        void getHitBySpell(const ASpell& spell) const;

    protected:
        std::string _type;
};

#endif
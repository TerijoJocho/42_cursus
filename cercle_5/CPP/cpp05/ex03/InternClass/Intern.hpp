#ifndef INTERN_HPP
#define INTERN_HPP

#pragma once
#include <iostream>
#include "../FormClass/AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern &operator=(const Intern & other);
    ~Intern();

    AForm*    makeForm(std::string form, std::string target) const;

private:

};

#endif
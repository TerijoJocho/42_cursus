#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
    for(int i = 0; i < 3; i++)
    {
        this->_types[i] = NULL;
    }
}

TargetGenerator::~TargetGenerator()
{
    for(int i = 0; i < 3; i++)
    {
        delete this->_types[i];
    }
}

TargetGenerator::TargetGenerator(TargetGenerator const &other)
{
    (void)other;
    return ;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other)
{
    (void)other;
    return (*this);
}

void    TargetGenerator::learnTargetType(ATarget* target)
{
    if (!target)
        return ;
    for(int i = 0; i < 3; i++)
    {
        if (this->_types[i] == NULL)
        {
            this->_types[i] = target->clone();
            return ;
        }
    }
} 

void    TargetGenerator::forgetTargetType(std::string const &target)
{
    for(int i = 0; i < 3; i++)
    {
        if (this->_types[i]->getType() == target)
        {
            delete this->_types[i];
            this->_types[i] = NULL;
            return ;
        }
    }
}
        
ATarget*    TargetGenerator::createTarget(std::string const & toCreate)
{
    for(int i = 0; i < 3; i++)
    {
        if (this->_types[i]->getType() == toCreate)
        {
            return this->_types[i]->clone();
        }
    }
    return NULL;
}
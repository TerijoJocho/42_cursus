#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practrice Dummy")
{
}
Dummy::~Dummy()
{
}

ATarget* Dummy::clone() const
{
    return new Dummy();
}
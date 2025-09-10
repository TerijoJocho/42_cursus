#include "myVect2.hpp"

myVect2::myVect2()
{
    this->_container.push_back(0);
    this->_container.push_back(0);
}

myVect2::myVect2(int x, int y)
{
    this->_container.push_back(x);
    this->_container.push_back(y);
}

myVect2::myVect2(const myVect2 &other)
{
    *this = other;
}

myVect2::~myVect2()
{
}

int myVect2::getContainer_elements(int idx) const
{
    return this->_container[idx];
}

/*ADDITION*/
    myVect2 myVect2::operator+(int add) const
    {
        myVect2 copy(*this);

        copy._container[0] += add;
        copy._container[1] += add;

        return copy;
    }

    myVect2 myVect2::operator+(const myVect2 &add) const
    {
        myVect2 copy(*this);

        copy._container[0] += add.getContainer_elements(0);
        copy._container[1] += add.getContainer_elements(1);

        return copy;
    }

    myVect2& myVect2::operator++(void)
    {
        this->_container[0] += 1;
        this->_container[1] += 1;
        return (*this);
    }

    myVect2 myVect2::operator++(int)
    {
        myVect2 copy(*this);
        
        this->_container[0] += 1;
        this->_container[1] += 1;
        return (copy);
    }

    myVect2 myVect2::operator+=(int add)
    {
        this->_container[0] += add;
        this->_container[1] += add;
        return *this;
    }

    myVect2 myVect2::operator+=(const myVect2 &add)
    {
        this->_container[0] += add.getContainer_elements(0);
        this->_container[1] += add.getContainer_elements(1);
        return *this;
    }

/*SOUSTRACTION*/
    myVect2 myVect2::operator-(int add) const
    {
        myVect2 copy(*this);

        copy._container[0] -= add;
        copy._container[1] -= add;

        return copy;
    }

    myVect2 myVect2::operator-(const myVect2 &add) const
    {
        myVect2 copy(*this);

        copy._container[0] -= add.getContainer_elements(0);
        copy._container[1] -= add.getContainer_elements(1);

        return copy;
    }

    myVect2& myVect2::operator--(void)
    {
        this->_container[0] -= 1;
        this->_container[1] -= 1;
        return (*this);
    }

    myVect2 myVect2::operator--(int)
    {
        myVect2 copy(*this);
        
        this->_container[0] -= 1;
        this->_container[1] -= 1;
        return (copy);
    }

    myVect2 myVect2::operator-=(int add)
    {
        this->_container[0] -= add;
        this->_container[1] -= add;
        return *this;
    }

    myVect2 myVect2::operator-=(const myVect2 &add)
    {
        this->_container[0] -= add.getContainer_elements(0);
        this->_container[1] -= add.getContainer_elements(1);
        return *this;
    }

/*MULTIPLICATION*/
    myVect2 myVect2::operator*(int mult) const
    {
        myVect2 copy(*this);

        copy._container[0] *= mult;
        copy._container[1] *= mult;

        return copy;
    }

    myVect2 myVect2::operator*(const myVect2 &mult) const
    {
        myVect2 copy(*this);

        copy._container[0] *= mult.getContainer_elements(0);
        copy._container[1] *= mult.getContainer_elements(1);
        
        return copy;
    }

    myVect2 myVect2::operator*=(int mult)
    {
        this->_container[0] *= mult;
        this->_container[1] *= mult;

        return *this;
    }

    myVect2 myVect2::operator*=(const myVect2 &v)
    {
        this->_container[0] *= v.getContainer_elements(0);
        this->_container[1] *= v.getContainer_elements(1);

        return *this;
    }

/*EQUAL*/
    myVect2& myVect2::operator=(const myVect2 &other)
    {
        if (this == &other)
            return *this;
        
        this->_container = other._container;
        return *this;
    }

    bool myVect2::operator==(const myVect2 &other) const
    {
        if ((this->getContainer_elements(0) == other.getContainer_elements(0)) 
            && (this->getContainer_elements(1) == other.getContainer_elements(1)))
            return true;
        return false;
    }

    bool myVect2::operator!=(const myVect2 &other) const
    {
        if ((this->getContainer_elements(0) != other.getContainer_elements(0)) 
            && (this->getContainer_elements(1) != other.getContainer_elements(1)))
            return true;
        return false;
    }

/*FONCTION LIBRE*/
    myVect2 operator*(int mult, const myVect2 &v)
    {
        return v * mult;
    }

    std::ostream&   operator<<(std::ostream &out, const myVect2 &v)
    {
        return out << "{" << v.getContainer_elements(0) << "," << v.getContainer_elements(1) << "}";
    }
#include "myBigInt.hpp"

myBigInt::myBigInt() : _string("0")
{
}

myBigInt::myBigInt(unsigned int n)
{
    std::stringstream   oss;
    oss << n;
    this->_string = oss.str();
}

myBigInt::myBigInt(const myBigInt& other) : _string(other.getValue())
{
}

myBigInt::~myBigInt()
{
}

std::string myBigInt::getValue() const
{
    return this->_string;
}

myBigInt    myBigInt::operator+(const myBigInt& other) const
{
    myBigInt    copy(*this);
    std::string ss1 = this->_string;
    std::string ss2 = other.getValue();

    if (ss2.size() > ss1.size())
        std::swap(ss1, ss2);
        
    std::string result = "";
    int i = ss1.length() - 1;
    int j = ss2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >=0 || carry)
    {
        int digit1 = 0;
        if (i >= 0)
            digit1 = ss1[i] - '0';
        
        int digit2 = j >= 0 ? ss2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;

        i--; j--;
    }
    copy._string = result;
    return copy;
}

myBigInt    myBigInt::operator+=(const myBigInt& other)
{
    *this = *this + other;
    return *this;
}

myBigInt    myBigInt::operator++(int)
{
    myBigInt    copy(*this);
    myBigInt    add(1);

    *this += add;
    return copy;
}

myBigInt&   myBigInt::operator++(void)
{
    myBigInt    add(1);

    *this += add;
    return *this;
}

myBigInt    myBigInt::operator<<(unsigned int value) const
{
    myBigInt    copy(*this);

    if (copy._string == "0")
        return copy;
    
    copy._string.append(value, '0');
    return copy;
}

myBigInt    myBigInt::operator<<=(unsigned int value)
{
    if (this->_string == "0")
        return *this;
    
    this->_string.append(value, '0');
    return *this;
}

myBigInt    myBigInt::operator>>=(const myBigInt& other)
{
    if (this->_string == "0")
        return *this;
    
    std::stringstream  oss;
    oss << other;
    size_t value = 0;
    oss >> value;

    if (this->_string.size() > value)
        this->_string.erase(this->_string.begin() + (this->_string.size() - value), this->_string.end());
    else
    {
        this->_string.clear();
        this->_string.push_back('0');
    }
    return *this;
}


bool        myBigInt::operator>(const myBigInt& other)
{
    if (this->_string.size() > other.getValue().size())
        return true;
    if (this->_string.size() < other.getValue().size())
        return false;
    
    std::string x1 = this->_string;
    std::string x2 = other.getValue();

    for (size_t i = 0; i < x1.size(); i++)
    {
        if (x1[i] != x2[i])
        {
            if (x1[i] > x2[i])
                return true;
            else
                return false;
        }
    }

    return false;
}

bool        myBigInt::operator<(const myBigInt& other)
{
    if (this->_string.size() != other.getValue().size())
        return this->_string.size() < other.getValue().size();
    
    return this->_string < other.getValue(); //lexicographical compare
}

bool        myBigInt::operator==(const myBigInt& other)
{
    return this->_string == other.getValue();
}

bool        myBigInt::operator!=(const myBigInt& other)
{
    return this->_string != other.getValue();
}

bool        myBigInt::operator<=(const myBigInt& other)
{
    if (*this == other)
        return true;
    if (*this < other)
        return true;
    return false;
}

bool        myBigInt::operator>=(const myBigInt& other)
{
    if (*this == other)
        return true;
    if (*this > other)
        return true;
    return false;
}


std::ostream&   operator<<(std::ostream& out, const myBigInt& other)
{
    return out << other.getValue();
}
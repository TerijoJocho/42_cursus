#include <iostream>
#include <string>
#include <ostream>
#include <sstream>

class myBigInt
{
    private :
        std::string _string;

    public :
        myBigInt();
        myBigInt(unsigned int n);
        myBigInt(const myBigInt& other);
        ~myBigInt();

        std::string getValue() const;

        myBigInt    operator+(const myBigInt& other) const;
        myBigInt&   operator+=(const myBigInt& other);
        myBigInt&   operator++(void);//pre
        myBigInt    operator++(int);//post
        myBigInt    operator<<(unsigned int value) const;//add 0, value times, return copy
        myBigInt&   operator<<=(unsigned int value);//add 0, value times, return *this
        myBigInt&    operator>>=(const myBigInt& other);//enleve 0, value fois, return *this

        bool        operator>(const myBigInt& other) const;
        bool        operator<(const myBigInt& other) const;
        bool        operator==(const myBigInt& other) const;
        bool        operator!=(const myBigInt& other) const;
        bool        operator<=(const myBigInt& other) const;
        bool        operator>=(const myBigInt& other) const;
};

std::ostream&   operator<<(std::ostream& out, const myBigInt& other);
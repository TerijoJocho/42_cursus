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
        myBigInt    operator+=(const myBigInt& other);
        myBigInt    operator++(int);
        myBigInt&   operator++(void);
        myBigInt    operator<<(unsigned int value) const;
        myBigInt    operator<<=(unsigned int value);
        myBigInt    operator>>=(const myBigInt& other);

        bool        operator>(const myBigInt& other);
        bool        operator<(const myBigInt& other);
        bool        operator==(const myBigInt& other);
        bool        operator!=(const myBigInt& other);
        bool        operator<=(const myBigInt& other);
        bool        operator>=(const myBigInt& other);
};

std::ostream&   operator<<(std::ostream& out, const myBigInt& other);
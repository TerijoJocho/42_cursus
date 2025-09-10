#include <iostream>
#include <vector>
#include <ostream>

class myVect2
{
    public:
        myVect2();//default constructor
        myVect2(int x, int y);//initialize constructor
        myVect2(const myVect2 &other);//copy constructor
        ~myVect2();//destructor

        int getContainer_elements(int idx) const;//getter

        myVect2 operator+(int add) const;//v + add
        myVect2 operator+(const myVect2 &add) const;//v + v
        myVect2& operator++(void);//++pre incrementation
        myVect2 operator++(int);//post++ incremantation
        myVect2 operator+=(int add);//v += add
        myVect2 operator+=(const myVect2 &add);//v += v

        myVect2 operator-(int add) const;//v - add
        myVect2 operator-(const myVect2 &add) const;//v - v
        myVect2& operator--(void);//++pre decrementation
        myVect2 operator--(int);//post++ decrementation
        myVect2 operator-=(int add);//v -= add
        myVect2 operator-=(const myVect2 &add);//v -= v

        myVect2 operator*(int mult) const;//v * mult
        myVect2 operator*(const myVect2 &mult) const;//v * v
        myVect2 operator*=(int mult);//v *= mult
        myVect2 operator*=(const myVect2 &v);//v *= v

        myVect2& operator=(const myVect2 &other);//copy assignment operator
        bool operator==(const myVect2 &other) const;//v1 == v2 ?
        bool operator!=(const myVect2 &other)const ;//v1 != v2 ?

    private:
        std::vector<int>    _container;
};

//fonction libre
myVect2         operator*(int mult, const myVect2 &v);//mult * v
std::ostream&   operator<<(std::ostream &out, const myVect2 &v); //to display v{x, y}
#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H
#include <number.h>
#include "cmath"

class Vector{
    const static Vector VECTOR_ONE;
    const static Vector VECTOR_ZERO;
public:
    Vector(Number x, Number y) : x_(x), y_(y) {};
    Number GetY();
    Number GetX();
    Number AngleCalculation();
    Number RadiusCalculation();
private:
    Number x_;
    Number y_;
};

#endif //VECTOR_LIBRARY_H

#include "vector.h"
#include <cmath>
#include <number.h>
#include <iostream>

const Vector ONE_ONE = Vector(Number(1), Number(1));
const Vector ZERO_ZERO = Vector(Number(0), Number(0));

Number Vector::GetY() {
    return y_;
}

Number Vector::GetX() {
    return x_;
}

Number Vector::AngleCalculation()
{
    return Number((int)atan(y_.GetNumber() / x_.GetNumber()));
}

Number Vector::RadiusCalculation()
{
    return Number((int)sqrt(x_.GetNumber() * x_.GetNumber() + y_.GetNumber() * y_.GetNumber()));
}









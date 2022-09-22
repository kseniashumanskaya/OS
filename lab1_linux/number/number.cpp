#include "number.h"
#include <iostream>

const Number ONE = 1;
const Number ZERO = 0;

Number Number::operator+(const Number &number2) {
    return Number(number_ + number2.number_);
}

Number Number::operator-(const Number &number2) {
    return Number(number_ - number2.number_);
}

Number Number::operator*(const Number &number2) {
    return Number(number_ * number2.number_);
}

Number Number::operator/(const Number &number2) {
    return Number(number_ / number2.number_);
}

Number Number::CreateNumber(int number) {
    return Number(number);
}

void Number::Print() {
    std::cout << number_;
}


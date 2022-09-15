#include <iostream>
#include "numbers.h"

int main()
{
    Number two = Number(2);
    Number seven = Number(7);
    Number number1 = seven / two;
    Number number2 = seven + two;
    Number number3 = seven * two;
    Number number4 = seven - two;
    number1.Print();
    std::cout << " ";
    number2.Print();
    std::cout << " ";
    number3.Print();
    std::cout << " ";
    number4.Print();
}

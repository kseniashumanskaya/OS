#ifndef NUMBER_LIBRARY_H
#define NUMBER_LIBRARY_H
#include <iostream>

class Number {
    static const Number ONE;
    static const Number ZERO;
public:
    Number (int number) : number_(number) {};
    Number operator+ (const Number& number2);
    Number operator- (const Number& number2);
    Number operator* (const Number& number2);
    Number operator/ (const Number& number2);
    Number CreateNumber(int number);
    int GetNumber(){
        return number_;
    }
    void Print();
private:
    int number_;
};

#endif //NUMBER_LIBRARY_H

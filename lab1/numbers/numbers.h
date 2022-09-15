#pragma once
#include <iostream>

	class Number {
		static const Number ONE;
		static const Number ZERO;
	public:
		Number(int number) : number_(number) {};
		Number operator+ (const Number& number2);
		Number operator- (const Number& number2);
		Number operator* (const Number& number2);
		Number operator/ (const Number& number2);
		Number CreateNumber(int number);
		int GetNumber();
		void Print();
	private:
		int number_;
	};



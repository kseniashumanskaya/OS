// numbers.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "numbers.h"

	const Number ONE = 1;
	const Number ZERO = 0;

	Number Number::operator+(const Number& number2)
	{
		return Number(number_ + number2.number_);
	}

	Number Number::operator-(const Number& number2)
	{
		return Number(number_ - number2.number_);
	}

	Number Number::operator*(const Number& number2)
	{
		return Number(number_ * number2.number_);
	}

	Number Number::operator/(const Number& number2)
	{
		return Number(number_ / number2.number_);
	}

	Number Number::CreateNumber(int number)
	{
		return Number(number);
	}

	int Number::GetNumber()
	{
		return number_;
	}

	void Number::Print()
	{
		std::cout << number_;
	}

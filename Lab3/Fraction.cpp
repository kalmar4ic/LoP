#include <iostream>
#include <ctime>
using namespace std;
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab3/src/lib/Fraction.h"

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

Fraction::Fraction(const Fraction& F)
{
	numerator = F.numerator;
	denominator = F.denominator;
}

Fraction::~Fraction()
{

}

istream& operator>>(istream& stream, Fraction& F)
{
	char slash;
	stream >> F.numerator >> slash >> F.denominator;
	return stream;
}

ostream& operator<<(ostream& stream, const Fraction& F)
{
	stream << F.numerator << "/" << F.denominator;
	return stream;
}

bool Fraction::operator==(const Fraction& F) const
{
	return numerator * F.denominator == F.numerator * denominator;
}

bool Fraction::operator>(const Fraction& F) const
{
	return numerator * F.denominator > F.numerator * denominator;
}

bool Fraction::operator<(const Fraction& F) const
{
	return numerator * F.denominator < F.numerator * denominator;
}

bool Fraction::operator>=(const Fraction& F) const
{
	return numerator * F.denominator >= F.numerator * denominator;
}

bool Fraction::operator<=(const Fraction& F) const
{
	return numerator * F.denominator <= F.numerator * denominator;
}

Fraction& Fraction::operator=(const Fraction& F)
{
	numerator = F.numerator;
	denominator = F.denominator;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& F)
{
	numerator = numerator * F.denominator + F.numerator * denominator;
	denominator = denominator * F.denominator;

	return *this;
}

Fraction& Fraction::operator/=(const int num)
{
	numerator = numerator * num;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction &F)
{
	numerator = numerator * F.denominator - F.numerator * denominator;
	denominator = denominator * F.denominator;

	return *this;
}

#pragma once
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& F);
    ~Fraction();

    friend istream& operator>> (istream& stream, Fraction& F);
    friend ostream& operator<< (ostream& stream, const Fraction& F);

    bool operator==(const Fraction& F) const;
    bool operator>(const Fraction& F) const;
    bool operator<(const Fraction& F) const;
    bool operator>=(const Fraction& F) const;
    bool operator<=(const Fraction& F) const;

    Fraction& operator=(const Fraction& F);
    Fraction& operator+=(const Fraction& F);
    Fraction& operator/=(const int num);
    Fraction& operator-=(const Fraction& F);
    
};
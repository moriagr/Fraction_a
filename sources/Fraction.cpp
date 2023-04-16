#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator)
        {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        int getDenominator()
        {
            return denominator;
        }
        int getNumerator()
        {
            return numerator;
        }
        Fraction operator+(const Fraction &other) const
        {
        }
        Fraction operator-(const Fraction &other) const
        {
        }
        Fraction operator*(const Fraction &other) const
        {
        }
        Fraction operator/(const Fraction &other) const
        {
        }
        Fraction operator==(const Fraction &other) const
        {
        }
        Fraction operator!=(const Fraction &other) const
        {
        }
        Fraction operator<(const Fraction &other) const
        {
        }
        Fraction operator>(const Fraction &other) const
        {
        }
        Fraction operator<=(const Fraction &other) const
        {
        }
        Fraction operator>=(const Fraction &other) const
        {
        }
        // pre-increment
        Fraction &operator++()
        {
        }
        // post-increment
        Fraction operator++(int)
        {
        }
        // pre-decrement
        Fraction &operator--()
        {
        }
        // post-decrement
        Fraction operator--(int)
        {
        }
        friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction)
        {
        }
        friend std::istream &operator>>(std::istream &input, const Fraction &fraction)
        {
        }
        Fraction &operator*(const Fraction &fraction)
        {
        }
        Fraction &operator+(const Fraction &fraction)
        {
        }
        Fraction &operator-(const Fraction &fraction)
        {
        }
        Fraction &operator/(const Fraction &fraction)
        {
        }
    };
}
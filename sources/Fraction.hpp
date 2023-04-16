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
        // Copy constructor
        Fraction(const Fraction &other);

        // Assignment operator
        Fraction &operator=(const Fraction &other);
        Fraction(int numerator, int denominator);

        int getDenominator();
        int getNumerator();

        Fraction &operator*(const Fraction &fraction);
        friend Fraction &operator*(const Fraction &fraction1, float fraction2);
        friend Fraction &operator*(float fraction1, const Fraction &fraction2);

        Fraction &operator/(const Fraction &fraction);
        friend Fraction &operator/(const Fraction &fraction1, float fraction2);
        friend Fraction &operator/(float fraction1, const Fraction &fraction2);

        Fraction &operator-(const Fraction &fraction);
        friend Fraction &operator-(const Fraction &fraction1, float fraction2);
        friend Fraction &operator-(float fraction1, const Fraction &fraction2);

        Fraction &operator+(const Fraction &fraction);
        friend Fraction &operator+(const Fraction &fraction1, float fraction2);
        friend Fraction &operator+(float fraction1, const Fraction &fraction2);

        Fraction &operator==(const Fraction &fraction);
        friend Fraction &operator==(const Fraction &fraction1, float fraction2);
        friend Fraction &operator==(float fraction1, const Fraction &fraction2);

        Fraction &operator!=(const Fraction &fraction);
        friend Fraction &operator!=(const Fraction &fraction1, float fraction2);
        friend Fraction &operator!=(float fraction1, const Fraction &fraction2);

        Fraction &operator<(const Fraction &fraction);
        friend Fraction &operator<(const Fraction &fraction1, float fraction2);
        friend Fraction &operator<(float fraction1, const Fraction &fraction2);

        Fraction &operator>(const Fraction &fraction);
        friend Fraction &operator>(const Fraction &fraction1, float fraction2);
        friend Fraction &operator>(float fraction1, const Fraction &fraction2);

        Fraction &operator<=(const Fraction &fraction);
        friend Fraction &operator<=(const Fraction &fraction1, float fraction2);
        friend Fraction &operator<=(float fraction1, const Fraction &fraction2);

        Fraction &operator>=(const Fraction &fraction);
        friend Fraction &operator>=(const Fraction &fraction1, float fraction2);
        friend Fraction &operator>=(float fraction1, const Fraction &fraction2);

        Fraction &operator++();   // pre-increment
        Fraction operator++(int); // post-increment
        Fraction &operator--();   // pre-decrement
        Fraction operator--(int); // post-decrement
        friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &input, const Fraction &fraction);
    };
}
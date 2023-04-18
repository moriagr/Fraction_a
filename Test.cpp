#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test original fraction")
{
    Fraction f1(1, 2);

    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
}

TEST_CASE("Test reduce fraction")
{
    Fraction f1(2, 4);

    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);
}

TEST_CASE("Test increment and decrement operators")
{
    Fraction f1(1, 2);

    CHECK((++f1).getNumerator() == 3);
    CHECK_NOTHROW(++ ++ ++ ++ ++ ++ ++ ++ ++f1);
    CHECK(f1.getNumerator() == 21);  // 2*9 + 3
    CHECK(f1.getDenominator() == 2); // 2*9 + 3

    CHECK((--f1).getNumerator() == 19); // 21-2*1 = 19
    CHECK_NOTHROW(-- -- -- -- -- -- -- -- --f1);
    CHECK(f1.getNumerator() == 1);   // 19 - 2*9 = 1
    CHECK(f1.getDenominator() == 2); // 2*9 + 3
    Fraction f2(3, 5);

    Fraction result = f2++;
    CHECK(f2.getNumerator() == 8);
    CHECK(f2.getDenominator() == 5);
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 5);

    Fraction result2 = f2--;
    CHECK(f2.getNumerator() == 3);
    CHECK(f2.getDenominator() == 5);
    CHECK(result2.getNumerator() == 8);
    CHECK(result2.getDenominator() == 5);
}

TEST_CASE("Test comparison operations")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);

    // Test operator==

    CHECK((f1 == f2) == true);

    Fraction f3(2, 4);

    CHECK((f1 == f3) == true);
    CHECK((f1 == 0.5) == true);

    // Test operator!=

    Fraction f4(3, 4);
    Fraction f5(8, 9);

    CHECK((f5 != f4) == true);

    Fraction f6(3, 7);
    CHECK((f3 != f6) == true);

    // Test operator<
    CHECK((f1 < f4) == true);

    CHECK(!(f4 < f6) == true);

    // Test operator>
    CHECK((f1 > f4) == true);

    Fraction f7(5, 6);
    Fraction f8(7, 8);

    CHECK(!(f7 > f8) == true);

    // Test operator<=
    Fraction f9(2, 3);
    Fraction f10(4, 5);
    CHECK((f9 <= f10) == true);

    Fraction f11(1, 2);
    Fraction f12(1, 3);
    CHECK(!(f11 <= f12) == true);

    // Test operator>=
    Fraction f13(3, 4);
    CHECK((f13 >= f11) == true);

    Fraction f14(5, 6);
    Fraction f15(5, 7);
    CHECK(!(f14 >= f15) == true);
}

TEST_CASE("Test arithmetic operators: + / - *")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    // Test operator*
    Fraction result1 = f1 * f2;

    CHECK(result1.getNumerator() == 3);
    CHECK(result1.getDenominator() == 8);

    Fraction f3(7, 8);
    Fraction f4(0, 3);

    Fraction result2 = f3 * f4;

    CHECK(result2.getNumerator() == 0);
    CHECK(result2.getDenominator() == 1);

    // Test operator/
    Fraction result3 = f1 / f2;

    CHECK(result3.getNumerator() == 2);
    CHECK(result3.getDenominator() == 3);

    Fraction f5(1, 2);
    Fraction f6(0, 7);

    CHECK_THROWS(f5 / f6);

    Fraction result4 = f6 / f5;
    CHECK(result4.getNumerator() == 0);
    CHECK(result4.getDenominator() == 1);

    // Test operator-

    Fraction result6 = f1 - f2;

    CHECK(result6.getNumerator() == -1);
    CHECK(result6.getDenominator() == 4);

    // Test operator+

    Fraction result7 = f1 + f2;

    CHECK(result7.getNumerator() == 5);
    CHECK(result7.getDenominator() == 4);

    Fraction f7(-1, 2);
    Fraction f8(3, 4);

    Fraction result8 = f7 + f8;

    CHECK(result8.getNumerator() == 1);
    CHECK(result8.getDenominator() == 4);
}

TEST_CASE("Test input and output operators")
{
    Fraction f1(3, 5);

    std::ostringstream output;
    output << f1;

    CHECK(output.str() == "3/5");

    Fraction f2;
    std::istringstream input("5/6");
    input >> f2;

    CHECK(f2.getNumerator() == 5);
    CHECK(f2.getDenominator() == 6);

    Fraction f3;
    std::istringstream input2("invalid input");

    CHECK_THROWS(input2 >> f2);
    CHECK(f3.getNumerator() == 0);
    CHECK(f3.getDenominator() == 1);
}

TEST_CASE("Test fraction with whole numbers")
{
    Fraction f1(3);

    std::ostringstream output;
    output << f1;

    CHECK(output.str() == "3");

    Fraction f2;
    std::istringstream input("5");
    input >> f2;

    CHECK(f2.getNumerator() == 5);
    CHECK(f2.getDenominator() == 1);

    Fraction f3(123456, 789012);

    std::ostringstream output2;
    output2 << f3;

    CHECK(output2.str() == "8232/52420");
}

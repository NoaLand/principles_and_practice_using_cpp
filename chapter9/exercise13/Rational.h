#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_RATIONAL_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_RATIONAL_H

#include "../lib/std_lib_facilities.h"

class Rational {
public:
    class Invalid: exception {
    public:
        explicit Invalid(string  e);
        const char* what() const noexcept override {
            return message.c_str();
        }
    private:
        string message;
    };
    Rational(int nn, int dd);
    int numerator() const { return n; }
    int denominator() const {return d; }
    double approximate() const { return approximate_val; }
private:
    int n;
    int d;
    double approximate_val{(n * 1.0) / d};
    void simplify();
};

ostream& operator<<(ostream& os, const Rational& r);
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);

int gcd(int n1, int n2);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_RATIONAL_H

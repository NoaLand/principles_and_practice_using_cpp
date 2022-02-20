#include "Rational.h"

#include <utility>

Rational::Rational(int nn, int dd): n{nn}, d{dd} {
    if(dd == 0) throw Invalid{"invalid denominator"};
}

Rational::Invalid::Invalid(string  e): message{std::move(e)} {
}

ostream &operator<<(ostream &os, const Rational &r) {
    return os << r.numerator() << "/" << r.denominator();
}

Rational operator+(const Rational &a, const Rational &b) {
    int n{a.numerator() * b.denominator() + b.numerator() * a.denominator()};
    int d{a.denominator() * b.denominator()};
    return {n, d};
}

Rational operator-(const Rational &a, const Rational &b) {
    int n{a.numerator() * b.denominator() - b.numerator() * a.denominator()};
    int d{a.denominator() * b.denominator()};
    return {n, d};
}

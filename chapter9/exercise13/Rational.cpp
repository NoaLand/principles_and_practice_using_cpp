#include "Rational.h"

#include <utility>

Rational::Rational(int nn, int dd): n{nn}, d{dd} {
    if(dd == 0) throw Invalid{"invalid denominator"};
    simplify();
}

void Rational::simplify() {
    int g = gcd(n, d);
    n = n/g;
    d = d/g;
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

Rational operator*(const Rational &a, const Rational &b) {
    int n{a.numerator() * b.numerator()};
    int d{a.denominator() * b.denominator()};
    return {n, d};
}

Rational operator/(const Rational &a, const Rational &b) {
    int n{a.numerator() * b.denominator()};
    int d{a.denominator() * b.numerator()};
    return {n, d};
}

bool operator==(const Rational &a, const Rational &b) {
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

int gcd(int n1, int n2) {
    if(n1 % n2 != 0) {
        return gcd(n2, n1 % n2);
    } else {
        return n2;
    }
}
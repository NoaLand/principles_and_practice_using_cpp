#include "Rational.h"

#include <utility>

Rational::Rational(int nn, int dd): n{nn}, d{dd} {
    if(dd == 0) throw Invalid{"invalid denominator"};
}

Rational::Invalid::Invalid(string  e): message{std::move(e)} {
}

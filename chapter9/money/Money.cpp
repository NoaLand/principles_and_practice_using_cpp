#include "Money.h"

Money::Money(double dollar): c{approximate_rule(dollar)} {
}

long int Money::approximate_rule(const double& d) {
    int temp = static_cast<int>(d * 100);
    if(temp + 0.5 <= d * 100) {
        ++temp;
    }
    return temp;
}

ostream &operator<<(ostream &os, const Money &m) {
    return os << "$" << m.cents() / 100.0;
}

#include "Money.h"

Money::Money(double dollar, Currency currency): c{approximate_rule(dollar)}, cur{currency} {
}

long int Money::approximate_rule(const double& d) {
    int temp = static_cast<int>(d * 100);
    if(temp + 0.5 <= d * 100) {
        ++temp;
    }
    return temp;
}

string Money::currency() const {
    switch (cur) {
        case Currency::USD:
            return "USD";
        case Currency::DKK:
            return "DKK";
        case Currency::CNY:
            return "CNY";
    }
}

ostream &operator<<(ostream &os, const Money &m) {
    return os << m.currency() << static_cast<double>(m.cents()) / 100.0;
}

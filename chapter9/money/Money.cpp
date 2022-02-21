#include "Money.h"

vector<Exchange_Rate> exchange_rate_list;

Money::Money(double dollar, Currency currency): c{approximate_rule(dollar)}, cur{currency} {
}

long int Money::approximate_rule(const double& d) {
    int temp = static_cast<int>(d * 100);
    if(temp + 0.5 <= d * 100) {
        ++temp;
    }
    return temp;
}

string Money::currency_string() const {
    switch (cur) {
        case Currency::USD:
            return "USD";
        case Currency::DKK:
            return "DKK";
        case Currency::CNY:
            return "CNY";
    }
}

Money::Money(): c{0}, cur{Currency::USD} {
}

ostream &operator<<(ostream &os, const Money &m) {
    return os << m.currency_string() << static_cast<double>(m.cents()) / 100.0;
}

Money operator+(const Money &m1, const Money &m2) {
    if(m1.currency() == m2.currency()) {
        return Money{static_cast<double>(m1.cents() + m2.cents()) / 100.0, m1.currency()};
    } else {
        double rate = get_rate(m2.currency(), m1.currency());
        return Money{static_cast<double>(m2.cents() * rate + m1.cents()) / 100.0, m1.currency()};
    }
}

double get_rate(Currency f, Currency t) {
    for(Exchange_Rate er : exchange_rate_list) {
        if(er.from == f && er.to == t) {
            return er.rate;
        }
    }

    simple_error("no rate found");
}

istream &operator>>(istream &is, Money &m) {
    string currency;
    double cents{0};

    for(char c; is >> c;) {
        if(!isdigit(c)) {
            currency += c;
        } else {
            is.putback(c);
            is >> cents;
            break;
        }
    }

    m = Money{cents, to_currency(currency)};

    return is;
}

Currency to_currency(const string &cs) {
    if(cs == "USD") {
        return Currency::USD;
    } else if(cs == "DKK") {
        return Currency::DKK;
    } else if(cs == "CNY") {
        return Currency::CNY;
    }
}

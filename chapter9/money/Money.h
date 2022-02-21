#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H
#include "../lib/std_lib_facilities.h"
enum class Currency {
    USD, DKK, CNY
};

struct Exchange_Rate {
    Currency from;
    Currency to;
    double rate;
};

extern vector<Exchange_Rate> exchange_rate_list;
double get_rate(Currency f, Currency t);

class Money {
public:
    Money();
    explicit Money(double dollar, Currency currency);

    long int cents() const { return c; }
    Currency currency() const { return cur; }
    string currency_string() const;
private:
    long int c;
    Currency cur;

    static long int approximate_rule(const double& d);
};

istream& operator>>(istream& is, Money& m);
ostream& operator<<(ostream& os, const Money& m);
Money operator+(const Money& m1, const Money& m2);
Currency to_currency(const string& cs);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H

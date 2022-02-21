#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H
#include "../lib/std_lib_facilities.h"
enum class Currency {
    USD, DKK, CNY
};

class Money {
public:
    explicit Money(double dollar, Currency currency);

    long int cents() const { return c; }
    string currency() const;
private:
    long int c;
    Currency cur;

    static long int approximate_rule(const double& d);
};

ostream& operator<<(ostream& os, const Money& m);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H

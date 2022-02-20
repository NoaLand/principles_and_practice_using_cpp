#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H
#include "../lib/std_lib_facilities.h"

class Money {
public:
    explicit Money(double dollar);

    long int cents() const { return c; }
private:
    long int c;

    static long int approximate_rule(const double& d);
};

ostream& operator<<(ostream& os, const Money& m);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_MONEY_H

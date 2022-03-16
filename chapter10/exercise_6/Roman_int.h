#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_ROMAN_INT_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_ROMAN_INT_H

#include "../lib/std_lib_facilities.h"

enum Roman_element {
    NONE = 999999, I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
};
const vector<Roman_element> CAN_BE_LEFT {I, X, C};
const vector<Roman_element> CAN_NOT_REPEAT {V, L, D};

class Roman_int {
public:
    vector<Roman_element> get_num() const { return roman_num; }
    bool validating(Roman_element re) const;
    int as_int() const;

    void push_back(const Roman_element &re);
private:
    vector<Roman_element> roman_num{NONE};
};

istream &operator>>(istream &is, Roman_int& r);
ostream &operator<<(ostream &os, const Roman_int& r);

Roman_element translating(const char &re);
string to_str(const Roman_element& re);

Roman_int to_roman(int& num);
void get_roman_ele(int& num, Roman_int& r);
vector<Roman_element> get_base(const int& num);

#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_ROMAN_INT_H

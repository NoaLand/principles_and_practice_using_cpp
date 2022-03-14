#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_ROMAN_INT_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_ROMAN_INT_H

#include "../lib/std_lib_facilities.h"

enum Roman_element {
    NONE = -1, I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
};

class Roman_int {
public:
    vector<Roman_element> get_num() const { return roman_num; }

    void push_back(const Roman_element &re);

private:
    vector<Roman_element> roman_num{NONE};
};

istream &operator>>(istream &is, Roman_int& r);
ostream &operator<<(ostream &os, const Roman_int& r);

Roman_element to_roman_element(const char &re);
string to_str(const Roman_element& re);

#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_ROMAN_INT_H

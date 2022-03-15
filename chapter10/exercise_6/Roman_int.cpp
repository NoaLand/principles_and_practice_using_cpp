#include "Roman_int.h"

void Roman_int::push_back(const Roman_element &re) {
    if(roman_num.size() == 1 && roman_num[0] == NONE) {
        roman_num.clear();
    }

    roman_num.push_back(re);
}

bool Roman_int::validating(Roman_element re) const {
    Roman_element last_element = roman_num[roman_num.size() - 1];
    Roman_element last_second_element = roman_num[roman_num.size() - 2];

    bool element_can_be_left = last_element < re
                               && std::find(CAN_BE_LEFT.begin(), CAN_BE_LEFT.end(), last_element) != CAN_BE_LEFT.end();

    bool element_not_consecutive_3_times = last_element != last_second_element && last_element != re;

    return element_can_be_left && element_not_consecutive_3_times;
}

istream &operator>>(istream &is, Roman_int& r) {
    for(char raw_roman; is >> raw_roman;) {
        if(raw_roman != ';') {
            Roman_element re = translating(raw_roman);
            if(r.validating(re)) {
                r.push_back(re);
            } else {
                simple_error("wrong format Roman number!");
            }
        } else {
            return is;
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Roman_int& r) {
    for(Roman_element re : r.get_num()) {
        os << to_str(re);
    }
    os << endl;

    return os;
}

Roman_element translating(const char &re) {
    switch(re) {
        case 'I':
            return I;
        case 'V':
            return V;
        case 'X':
            return X;
        case 'L':
            return L;
        case 'C':
            return C;
        case 'D':
            return D;
        case 'M':
            return M;
        default:
            simple_error("wrong roman number format!");
    }
}

string to_str(const Roman_element &re) {
    switch(re) {
        case NONE:
            simple_error("Roman has no init");
        case I:
            return "I";
        case V:
            return "V";
        case X:
            return "X";
        case L:
            return "L";
        case C:
            return "C";
        case D:
            return "D";
        case M:
            return "M";
    }
}

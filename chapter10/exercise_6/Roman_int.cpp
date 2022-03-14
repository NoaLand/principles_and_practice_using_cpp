#include "Roman_int.h"

istream &operator>>(istream &is, Roman_int& r) {
    for(char raw_roman; is >> raw_roman;) {
        if(raw_roman != ';') {
            Roman_element re = to_roman_element(raw_roman);
            r.push_back(re);
        } else {
            return is;
        }
    }
    return is;
}

Roman_element to_roman_element(const char &re) {
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

ostream &operator<<(ostream &os, const Roman_int& r) {
    for(Roman_element re : r.get_num()) {
        os << to_str(re);
    }
    os << endl;

    return os;
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

void Roman_int::push_back(const Roman_element &re) {
    if(roman_num.size() == 1 && roman_num[0] == NONE) {
        roman_num.clear();
    }

    roman_num.push_back(re);
}

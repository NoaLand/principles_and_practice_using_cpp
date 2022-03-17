#include "Roman_int.h"

vector<char> roman_element_str{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void Roman_int::push_back(const Roman_element &re) {
    if(roman_num.size() == 1 && roman_num[0] == NONE) {
        roman_num.clear();
    }

    roman_num.push_back(re);
}

bool Roman_int::validating(Roman_element re) const {
    Roman_element last_element = roman_num[roman_num.size() - 1];
    Roman_element last_second_element = roman_num[roman_num.size() - 2];
    Roman_element last_third_element = roman_num[roman_num.size() - 3];

    bool element_can_be_left = (last_element < re
                               && std::find(CAN_BE_LEFT.begin(), CAN_BE_LEFT.end(), last_element) != CAN_BE_LEFT.end())
                               || last_element >= re;

    bool element_not_consecutive_3_times = !(last_third_element == last_second_element && last_second_element == last_element && last_element == re)
                                           || roman_num.size() <= 2;

    bool can_repeat = !(last_element == re && std::find(CAN_NOT_REPEAT.begin(), CAN_NOT_REPEAT.end(), last_element) != CAN_NOT_REPEAT.end());

    return element_can_be_left && element_not_consecutive_3_times && can_repeat;
}

int Roman_int::as_int() const {
    int res{roman_num[0]};
    for(int index = 1; index < roman_num.size(); ++index) {
        int this_num{roman_num[index]};
        int last_num{roman_num[index - 1]};

        if(last_num < this_num) {
            res = res - 2 * last_num + this_num;
        } else {
            res += this_num;
        }
    }

    return res;
}

istream &operator>>(istream &is, Roman_int& r) {
    for(char raw_roman; is >> raw_roman;) {
        if(in_element_vec(raw_roman)) {
            Roman_element re = translating(raw_roman);
            if(r.validating(re)) {
                r.push_back(re);
            } else {
                simple_error("wrong format Roman number!");
            }
        } else {
            is.putback(raw_roman);
            return is;
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Roman_int& r) {
    for(Roman_element re : r.get_num()) {
        os << to_str(re);
    }

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

Roman_int to_roman(int &num) {
    Roman_int r;
    get_roman_ele(num, r);
    return r;
}

void get_roman_ele(int &num, Roman_int& r) {
    if(num > 0) {
        vector<Roman_element> base = get_base(num);
        // TODO: waiting for refactoring, this ugly implement is only a quit test for int to roman number
        if(base.size() == 1) {
            num -= base[0];
            r.push_back(base[0]);
        } else {
            num -= (base[1] - base[0]);
            r.push_back(base[0]);
            r.push_back(base[1]);
        }
        get_roman_ele(num, r);
    }
}

vector<Roman_element> get_base(const int& num) {
    if(num >= M) {
        return {M};
    }

    if(num >= D) {
        if(num >= 900) {
            return {C, M};
        }
        return {D};
    }

    if(num >= C) {
        if(num >= 4 * C) {
            return {C, D};
        }
        return {C};
    }

    if(num >= L) {
        if(num >= 90) {
            return {X, C};
        }
        return {L};
    }

    if(num >= X) {
        if(num >= 4 * X) {
            return {X, L};
        }
        return {X};
    }

    if(num >= V) {
        if(num >= 9) {
            return {I, X};
        }
        return {V};
    }

    if(num >= I) {
        if(num >= 4 * I) {
            return {I, V};
        }
        return {I};
    }

    return {NONE};
}

bool in_element_vec(char raw) {
    for(char e : roman_element_str) {
        if(e == raw) return true;
    }

    return false;
}

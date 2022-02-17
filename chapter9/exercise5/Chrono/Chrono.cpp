#include "Chrono.h"

#include<ctime>

namespace Chrono {
    const Date& default_date() {
        static Date dd {2001, Month::jan, 1};
        return dd;
    }

    Date::Date(): year{default_date().year}, month{default_date().month}, day{default_date().day} {
    }

    Date::Date(int y, Month m, int d): year{y}, month{m}, day{d} {
        if(!is_date(y, m, d)) throw Invalid_date{};
    }

    std::ostream& operator<<(std::ostream& os, const Date& d) {
        return os << '(' << d.get_year()
                  << ',' << int(d.get_month())
                  << ',' << d.get_day() << ')';
    }

    std::istream& operator>>(std::istream& is, Date& dd) {
        int y, m, d;
        char ch2, ch3;
        is >> y >> ch2 >> m >> ch3 >> d;

        if(!is) return is;
        if(ch2 != '-' || ch3 != '-') {
            is.clear(std::ios_base::failbit);
            throw Date::Invalid_date{};
        }

        dd = Date(y, Month(m), d);

        return is;
    }

    bool is_date(int y, Month m, int d) {
        if(y <= 1980) return false;
        if(d <= 0) return false;
        if(m < Month::jan || m > Month::dec) return false;

        int days_in_month;

        switch (m) {
            case Month::feb:
                days_in_month = 28;
                break;
            case Month::apr: case Month::jun: case Month::sep: case Month::nov:
                days_in_month = 30;
                break;
            default:
                days_in_month = 31;
                break;
        }

        if(days_in_month < d) return false;

        return true;
    }

    Date today(){
        time_t t = time(nullptr);
        tm *const now = localtime(&t);
        return Date{1900 + now->tm_year, Month(now->tm_mon), now->tm_mday};
    }
}

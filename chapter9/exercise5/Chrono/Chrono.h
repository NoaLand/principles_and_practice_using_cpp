#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_CHRONO_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_CHRONO_H
#include "../lib/std_lib_facilities.h"

namespace Chrono {
    enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Date {
    public:
        class Invalid_date: exception {};
        Date();
        Date(int y, Month m, int d);

        int get_year() const { return year; }
        Month get_month() const { return month; }
        int get_day() const { return day; }
    private:
        int year;
        Month month;
        int day;
    };

    const Date& default_date();

    istream& operator>>(istream& is, Date& d);
    ostream& operator<<(ostream& os, const Date& d);

    bool is_date(int y, Month m, int d);
}
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_CHRONO_H

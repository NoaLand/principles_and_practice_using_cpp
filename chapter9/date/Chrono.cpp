#include "Chrono.h"

namespace Chrono {
    Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {
        if(!is_date(yy, mm, dd)) throw Invalid{};
    }

    const Date& default_date() {
        static Date dd {2001, Month::jan, 1};
        return dd;
    }

    Date::Date(): y{default_date().year()}, m{default_date().month()}, d{default_date().day()}{}

    void Date::add_day(int n) {
        int day_in_month = get_day_in_month(y, m);

        if(d + n < day_in_month) {
            d = d + n;
            return;
        }

        while(d + n > day_in_month) {
            d = d + n - day_in_month;

            if(int(m) + 1 > 12) {
                m = Month(1);
                y += 1;
            } else {
                m = Month(int(m) + 1);
            }

            day_in_month = get_day_in_month(y, m);
            // n should only use once, when getting into this loop
            n = 0;
        }
    }

    void Date::add_month(int n) {
        // ...
    }

    void Date::add_year(int n) {
        if(m == Month::feb && d == 29 && !leapyear(y + n)) {
            m = Month::mar;
            d = 1;
        }
        y += n;
    }

    // helper function:
    bool is_date(int y, Month m, int d) {
        if(d <= 0) return false;
        if(m < Month::jan || m > Month::dec) return false;

        int days_in_month;

        days_in_month = get_day_in_month(y, m);

        if(days_in_month < d) return false;

        return true;
    }

    int get_day_in_month(int y, const Month &m) {
        int days_in_month;
        switch (m) {
            case Month::feb:
                days_in_month = (leapyear(y)) ? 29 : 28;
                break;
            case Month::apr: case Month::jun: case Month::sep: case Month::nov:
                days_in_month = 30;
                break;
            default:
                days_in_month = 31;
                break;
        }
        return days_in_month;
    }

    bool leapyear(int y) {
        if(y % 100 == 0) {
            if(y % 400 == 0) {
                return true;
            }
        } else {
            if(y % 4 == 0) {
                return true;
            }
        }

        return false;
    }

    bool operator==(const Date& a, const Date& b) {
        return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b) {
        return !(a == b);
    }

    std::ostream& operator<<(std::ostream& os, const Date& d) {
        return os << '(' << d.year()
                    << ',' << int(d.month())
                    << ',' << d.day() << ')';
    }

    std::istream& operator>>(std::istream& is, Date& dd) {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

        if(!is) return is;
        if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
            is.clear(std::ios_base::failbit);
            return is;
        }

        dd = Date(y, Month(m), d);

        return is;
    }

    Day day_of_week(const Date& d) {
        int k = d.day();
        int m_abs = int(d.month());
        int m_rel = (m_abs > 2) ? m_abs - 2 : 10 + m_abs;
        int c = d.year() / 100;
        int y = d.year() - c * 100 - (m_abs > 2 ? 0 : 1);

        int param1 = 2.6 * m_rel - 0.2;
        int param2 = y / 4;
        int param3 = c / 4;
        int w = (k + param1 - 2 * c + y + param2 + param3) % 7;

        return Day(w);
    }

    Date next_sunday(const Date& d) {
        // ...
    }

    Date next_weekday(const Date& d) {
        // ...
    }

    Date next_workday(Date& d) {
        switch (day_of_week(d)) {
            case Day::sunday:
            case Day::monday:
            case Day::tuesday:
            case Day::wednesday:
            case Day::thursday:
                d.add_day(1);
            case Day::friday:
                d.add_day(3);
            case Day::saturday:
                d.add_day(2);
        }

        return d;
    }
}

#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_CHRONO_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_CHRONO_H
#include<iostream>
namespace Chrono {
    enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    enum class Day {
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };

    class Date {
    public:
        class Invalid {};
        Date(int y, Month m, int d);
        Date();

        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

    private:
        int y;
        Month m;
        int d;
    };

    bool is_date(int y, Month m, int d);
    bool leapyear(int y);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);

    std::istream& operator>>(std::istream& is, Date& dd);
    Date next_workday(Date& d);
}
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_CHRONO_H

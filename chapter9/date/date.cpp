#include "../lib/std_lib_facilities.h"

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m) {
    m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);

    return m;
}

Month int_to_month(int x) {
    if(x < int(Month::jan) || int(Month::dec) < x) simple_error("bad month");

    return Month(x);
}

class Date {
public:
    class Invalid {};
    Date(int y, Month m, int d);
    void add_day(int n);
    Month month() { return m; }
    int day() { return d; }
    int year() { return y; }

private:
    int y, d;
    Month m;
    bool is_valid();
};

Date::Date(int y, Month m, int d): y{y}, m{m}, d{d} {
    if(!is_valid()) throw Invalid{};
}

void Date::add_day(int n) {
}

bool Date::is_valid() {
    if(int(m) < 1 || 12 < int(m)) return false;
}

void f(int m) {
    Month mm = int_to_month(m);
}

int main() {
    keep_window_open();
    return 0;
}
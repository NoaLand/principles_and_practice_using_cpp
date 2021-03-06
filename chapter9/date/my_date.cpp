#include "../lib/std_lib_facilities.h"

class Year {
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid {};
    Year(int x): y{x} { if(x < min || x > max) throw Invalid{}; }
    int year() { return y; }

private:
    int y;
};

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
    Date();
    Date(Year y, Month m, int d);
    // this kind of function with `const` means, function not changing value in a class, so that this function can be called
    // in some function like this: `void some_func(const Date& start_of_term) { start_of_term.month(); }`.
    // If there's no `const` after, compiler will complain an error
    Month month() const { return m; }
    int day() const { return d; }
    Year year() const { return y; }

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
private:
    Year y;
    Month m;
    int d;
    bool is_valid();
};

const Date& default_date() {
    static Date dd{Year{2001}, Month::jan, 1};

    return dd;
}

Date::Date(Year y, Month m, int d): y{y}, m{m}, d{d} {
    if(!is_valid()) throw Invalid{};
}

void Date::add_day(int n) {
}

bool Date::is_valid() {
    if(int(m) < 1 || 12 < int(m)) return false;
}

Date::Date(): y{default_date().y}, m{default_date().m}, d{default_date().d} {
}

void f(int m) {
    Month mm = int_to_month(m);
}

int main() {
    keep_window_open();
    return 0;
}
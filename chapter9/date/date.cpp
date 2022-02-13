#include "../lib/std_lib_facilities.h"

class Date {
public:
    class Invalid {};
    Date(int y, int m, int d);
    void add_day(int n);
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }

private:
    int y, m, d;
    bool is_valid();
};

Date::Date(int y, int m, int d): y{y}, m{m}, d{d} {
    if(!is_valid()) throw Invalid{};
}

void Date::add_day(int n) {
}

bool Date::is_valid() {
    if(m < 1 || 12 < m) return false;
}

int main() {
    keep_window_open();
    return 0;
}
#include "../lib/std_lib_facilities.h"

struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};

int main() {
    keep_window_open();
    return 0;
}
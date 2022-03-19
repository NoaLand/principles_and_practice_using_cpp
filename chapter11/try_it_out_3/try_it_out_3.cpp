#include "../lib/std_lib_facilities.h"

int main() {
    cout << defaultfloat << 1234567.89 << '\t';
    cout << fixed << 1234567.89 << '\t';
    cout << scientific << 1234567.89 << '\t';

    keep_window_open();
    return 0;
}

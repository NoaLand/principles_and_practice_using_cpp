#include "../lib/std_lib_facilities.h"

int main() {
    int a, b, c, d;
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << endl;

    keep_window_open();
    return 0;
}

/**
 * input: 1234 4d2 2322 2322
 * output: 1234 1234 1234 1234
 *
 * input: 1234 1234 1234 1234
 * output: 1234 4660 668 668
 *
 * cin will just perform like cout
 * */

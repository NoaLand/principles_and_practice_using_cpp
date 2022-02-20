#include "Rational.h"

int main() {
    Rational r1{10, 3};
    double approximate_val1 = r1.approximate();
    cout << "approximate value 1 is: " << approximate_val1 << endl;

    Rational r2{10, 2};
    double approximate_val2 = r2.approximate();
    cout << "approximate value 2 is: " << approximate_val2 << endl;

    try{
        Rational invalid_r3{2, 0};
    } catch (Rational::Invalid& e) {
        cout << "exception: " << e.what() << endl;
    }

    keep_window_open();
    return 0;
}
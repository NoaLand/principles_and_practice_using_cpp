#include "Rational.h"

int main() {
    Rational r1{10, 3};
    double approximate_val1 = r1.approximate();
    cout << "r1 is: " << r1 << endl;
    cout << "approximate value 1 is: " << approximate_val1 << endl;

    Rational r2{10, 2};
    double approximate_val2 = r2.approximate();
    cout << "r2 is: " << r2 << endl;
    cout << "approximate value 2 is: " << approximate_val2 << endl;

    try{
        Rational invalid_r3{2, 0};
    } catch (Rational::Invalid& e) {
        cout << "exception: " << e.what() << endl;
    }

    Rational add_res = r1 + r2;
    double approximate_val4 = add_res.approximate();
    cout << "add res is: " << add_res << endl;
    cout << "approximate value of add is: " << approximate_val4 << endl;

    Rational minus_res = r1 - r2;
    double approximate_val5 = minus_res.approximate();
    cout << "minus res is: " << minus_res << endl;
    cout << "approximate value of minus is: " << approximate_val5 << endl;

    Rational multiplication_res = r1 * r2;
    double approximate_val6 = multiplication_res.approximate();
    cout << "multiplication res is: " << multiplication_res << endl;
    cout << "approximate value of multiplication is: " << approximate_val6 << endl;

    Rational divide_res = r1 / r2;
    double approximate_val7 = divide_res.approximate();
    cout << "divided res is: " << divide_res << endl;
    cout << "approximate value of divide is: " << approximate_val7 << endl;

    keep_window_open();
    return 0;
}
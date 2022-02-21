#include "Money.h"

int main() {
    Money m1{12.345, Currency::USD};
    cout << "m1: " << m1 << endl;

    Money m2{12.344, Currency::DKK};
    cout << "m2: " << m2 << endl;

    keep_window_open();
    return 0;
}
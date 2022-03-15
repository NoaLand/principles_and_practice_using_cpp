#include "Roman_int.h"

int main() {
    while(true) {
        cout << "Please enter roman number: ";
        Roman_int r;
        cin >> r;

        cout << "Roman " << r << " equals " << r.as_int() << endl;
    }

    keep_window_open();
    return 0;
}

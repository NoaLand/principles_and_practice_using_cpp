#include "Roman_int.h"

int main() {
    while(true) {
        cout << "Please enter roman number: ";
        Roman_int r_to_int;
        cin >> r_to_int;
        cout << "Roman " << r_to_int << " equals " << r_to_int.as_int() << endl;

        cout << "Please enter int number: ";
        int n;
        cin >> n;
        Roman_int r_from_int = to_roman(n);
        cout << "Roman " << r_from_int << endl;
    }

    keep_window_open();
    return 0;
}

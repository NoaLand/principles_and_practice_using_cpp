#include "../lib/std_lib_facilities.h"

int main() {
    // reset cin
    cin.unsetf(ios::dec);
    cin.unsetf(ios::hex);
    cin.unsetf(ios::oct);

    keep_window_open();
    return 0;
}

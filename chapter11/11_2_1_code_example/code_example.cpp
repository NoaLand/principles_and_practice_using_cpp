#include "../lib/std_lib_facilities.h"

int main() {
    cout << 1234 << "\t(decimal)\n"
         << hex << 1234 << "\t(hexadecimal)\n"
         << oct << 1234 << "\t(octal)\n";
    
    keep_window_open();
    return 0;
}

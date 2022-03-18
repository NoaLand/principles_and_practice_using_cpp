#include "../lib/std_lib_facilities.h"

int main() {
    cout << 1234 << "\t(decimal)\n"
         << hex << 1234 << "\t(hexadecimal)\n"
         << oct << 1234 << "\t(octal)\n";

    // this will still stay on octal format
    cout << 1234 << "\n";

    // reinit cout
    cout << dec;

    // another example
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << showbase << dec;
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    cout << noshowbase << dec;
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';

    keep_window_open();
    return 0;
}

/**
 * oct, dec, hex, showbase, noshowbase can help you to format your own number format
 * */
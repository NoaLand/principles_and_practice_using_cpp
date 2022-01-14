#include <../lib/std_lib_facilities.h>

void try_it_out_print_char_and_num();

int main() {
    try_it_out_print_char_and_num();

    keep_window_open();
    return 0;
}

void try_it_out_print_char_and_num() {
    int start = 0;
    while (int{'a'} + start <= 122) {
        char c = char('a' + start);
        cout << c << "\t" << int{c} << endl;
        ++start;
    }
}

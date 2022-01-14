#include <../lib/std_lib_facilities.h>

void try_it_out_print_char_and_num_while_version();

void try_it_out_print_char_and_num_for_version();

void print_char_range(char start_char, char end_char);

void try_it_out_square_without_times();

int my_square(int num);

int main() {
    // try_it_out_print_char_and_num_while_version();
    // try_it_out_print_char_and_num_for_version();
    try_it_out_square_without_times();

    keep_window_open();
    return 0;
}

void try_it_out_square_without_times() {
    int res = my_square(9);
    cout << "res: " << res << endl;
}

int my_square(int num) {
    int res{0};
    for(int index = 0; index < num; ++index) {
        res += num;
    }
    return res;
}

void try_it_out_print_char_and_num_for_version() {
    print_char_range('a', 'z');
    print_char_range('A', 'Z');
}

void print_char_range(char start_char, char end_char) {
    for(int offset = 0; int{start_char} + offset <= int{end_char}; ++offset) {
        char c = char(start_char + offset);
        cout << c << "\t" << int{c} << endl;
    }
}

void try_it_out_print_char_and_num_while_version() {
    int start{0};
    while (int{'a'} + start <= 122) {
        char c = char('a' + start);
        cout << c << "\t" << int{c} << endl;
        ++start;
    }
}

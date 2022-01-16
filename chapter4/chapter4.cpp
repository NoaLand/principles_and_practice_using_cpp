#include <../lib/std_lib_facilities.h>

void try_it_out_print_char_and_num_while_version();

void try_it_out_print_char_and_num_for_version();

void print_char_range(char start_char, char end_char);

void try_it_out_square_without_times();

int my_square(int num);

void try_it_out_dislike_words_bleep();

[[noreturn]] void exercise_1_print_two_nums_in_each_iteration();

int main() {
    // try_it_out_print_char_and_num_while_version();
    // try_it_out_print_char_and_num_for_version();
    // try_it_out_square_without_times();
    // try_it_out_dislike_words_bleep();
    exercise_1_print_two_nums_in_each_iteration();

    keep_window_open();
    return 0;
}

void exercise_1_print_two_nums_in_each_iteration() {
    double num1, num2;
    double max, min;
    while(cin >> num1 >> num2) {
        if(num1 == num2) {
            cout << "the numbers are equal" << endl;
        } else {
            max = num1 > num2 ? num1 : num2;
            min = num1 < num2 ? num1 : num2;

            if(max - min < 1.0 / 100) {
                cout << "the numbers are almost equal" << endl;
            } else {
                cout << "the smaller value is: " << min << endl;
                cout << "the larger value is: " << max << endl;
            }
        }
    }
}

void try_it_out_dislike_words_bleep() {
    const string disliked{"Broccoli"};
    cout << "please enter dict:" << endl;

    vector<string> dict;
    for(string word; cin >> word;) {
        if(word == "end") break;
        dict.push_back(word);
    }

    for(const string& word : dict) {
        if(word == disliked) {
            cout << "BLEEP" << endl;
        } else {
            cout << word << endl;
        }
    }
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

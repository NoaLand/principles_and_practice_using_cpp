#include <../lib/std_lib_facilities.h>
#include <cfloat>

void try_it_out_print_char_and_num_while_version();

void try_it_out_print_char_and_num_for_version();

void print_char_range(char start_char, char end_char);

void try_it_out_square_without_times();

int my_square(int num);

void try_it_out_dislike_words_bleep();

void exercise_1_print_two_nums_in_each_iteration();

void exercise_6_get_one_double_and_print_res();

double transfer_num_to_cm(double num, const string& unit);

void check_unit(const string& unit);

void exercise_7_calculate_mid_value();

void exercise_8_input_distance_between_two_cities();

void exercise_9_guess_number();

int main() {
    // try_it_out_print_char_and_num_while_version();
    // try_it_out_print_char_and_num_for_version();
    // try_it_out_square_without_times();
    // try_it_out_dislike_words_bleep();
    // exercise_1_print_two_nums_in_each_iteration();
    // exercise_6_get_one_double_and_print_res();
    // exercise_7_calculate_mid_value();
    // exercise_8_input_distance_between_two_cities();
    exercise_9_guess_number();

    keep_window_open();
    return 0;
}

void exercise_9_guess_number() {
    string answer;
    int times{1};
    int guess_number{50};
    int start{0}, end{100};

    cout << "********** guess number **********" << endl;
    cout << times << ". if your number is less than " << guess_number << "?\n";
    while(cin >> answer) {
        ++times;

        if(answer == "y") {
            end = guess_number;
        }

        if(answer == "n") {
            start = guess_number;
        }

        guess_number = (start + end) / 2;

        if(end - start == 1 || end - start == 2) {
            cout << "Your number is " << guess_number << endl;
            break;
        }

        cout << times << ". if your number is less than " << guess_number << "?" << endl;
    }
}

void exercise_8_input_distance_between_two_cities() {
    vector<double> ways;

    for(double distance; cin >> distance;) {
        ways.push_back(distance);
    }

    std::sort(ways.begin(), ways.end());

    double sum = accumulate(ways.begin(), ways.end(), 0.0);
    cout << "the sum of whole ways is: " << sum << endl;
    cout << "min distance is: " <<  ways.at(0) << endl;
    cout << "max distance is: " << ways.at(ways.size() - 1) << endl;
    cout << "average distance is: " << sum * 1.0 / ways.size() << endl;
}

void exercise_7_calculate_mid_value() {
    vector<double> data_list;
    double lval, rval;
    for(double data; cin >> data;) {
        data_list.push_back(data);
    }

    std::sort(data_list.begin(), data_list.end());
    data_list.erase(unique(data_list.begin(), data_list.end()), data_list.end());

    if(data_list.size() % 2 == 0) {
        lval = data_list[data_list.size() / 2 - 1];
        rval = data_list[data_list.size() / 2];
    } else {
        lval = data_list[data_list.size() / 2];
        rval = lval;
    }

    cout << "the mid value is: " << (lval + rval) / 2 << endl;
}

void exercise_6_get_one_double_and_print_res() {
    double num, num_after_transfer_to_cm, max{DBL_MIN}, min{DBL_MAX};
    string unit;

    vector<double> data;

    while(cin >> num >> unit) {
        check_unit(unit);

        cout << "num is: " << num << unit << endl;

        num_after_transfer_to_cm = transfer_num_to_cm(num, unit);

        if(num_after_transfer_to_cm > max) {
            max = num_after_transfer_to_cm;
            cout << "the largest so far" << endl;
        }

        if(num_after_transfer_to_cm < min) {
            min = num_after_transfer_to_cm;
            cout << "the smallest so far" << endl;
        }

        data.push_back(num_after_transfer_to_cm);
    }

    cout << "-----------" << endl;
    sort(data.begin(), data.end());
    for(double d : data) {
        cout << d << "cm" << endl;
    }
    cout << "-----------" << endl;
    cout << "min num is: " << min << "cm" << endl;
    cout << "max num is: " << max << "cm" << endl;
    cout << "sum is: " << std::accumulate(data.begin(), data.end(), 0.0) << "cm" << endl;
    cout << "total input num is: " << data.size() << endl;
    cout << "-----------" << endl;
}

void check_unit(const string& unit) {
    if(unit != "cm" && unit != "m" && unit != "in" && unit != "ft") {
        simple_error("unit is wrong!");
    }
}

double transfer_num_to_cm(double num, const string& unit) {
    if(unit == "cm") {
        return num * 1.0;
    } else if(unit == "m") {
        return num * 100.0;
    } else if(unit == "in") {
        return num * 2.54;
    } else if(unit == "ft") {
        return transfer_num_to_cm(num * 12, "in");
    }
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

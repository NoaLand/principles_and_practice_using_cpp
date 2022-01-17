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

double transfer_num_to_cm(double num, const string &unit);

void check_unit(const string &unit);

void exercise_7_calculate_mid_value();

void exercise_8_input_distance_between_two_cities();

void exercise_9_guess_number();

void exercise_10_customize_calculator();

void exercise_11_string_to_num();

int find_and_get_index(vector<string> data_list, const string &element);

void exercise_12_get_num_or_string_customized_calculator();

void exercise_13_chess_puzzle();

void exercise_14_rock_paper_scissors_game();

void exercise_15_find_primes_between_1_to_100();

int main() {
    // try_it_out_print_char_and_num_while_version();
    // try_it_out_print_char_and_num_for_version();
    // try_it_out_square_without_times();
    // try_it_out_dislike_words_bleep();
    // exercise_1_print_two_nums_in_each_iteration();
    // exercise_6_get_one_double_and_print_res();
    // exercise_7_calculate_mid_value();
    // exercise_8_input_distance_between_two_cities();
    // exercise_9_guess_number();
    // exercise_10_customize_calculator();
    // exercise_11_string_to_num();
    // exercise_12_get_num_or_string_customized_calculator();
    // exercise_13_chess_puzzle();
    // exercise_14_rock_paper_scissors_game();
    exercise_15_find_primes_between_1_to_100();

    keep_window_open();
    return 0;
}

void exercise_15_find_primes_between_1_to_100() {
    vector<int> primes{2};

    for(int num = 3; num <= 100; ++num) {
        bool res{true};
        for(int prime : primes) {
            if(num % prime != 0) {
                res = res & true;
            } else {
                res = res & false;
            }
        }

        if(res) {
            primes.push_back(num);
        }
    }

    cout << "total size: " << primes.size() << endl;
    for(int prime : primes) {
        cout << prime << " ";
    }
}

int find_and_get_index(vector<string> data_list, const string &element) {
    auto res = find(data_list.begin(), data_list.end(), element);

    if (res != data_list.end()) {
        int index = res - data_list.begin(); // NOLINT(cppcoreguidelines-narrowing-conversions)
        return index;
    } else {
        simple_error("not in vector");
    }
}

void exercise_14_rock_paper_scissors_game() {
    vector<string> operate{"r", "p", "s"};
    vector<string> rule{"s", "r", "p", "s", "r"};
    for(string my_turn; cin >> my_turn;) {
        string computer_turn = operate.at(rand() % 3);

        if(my_turn == computer_turn) {
            cout << "Tieeeeeee!" << endl;
            cout << "************" << endl;
            continue;
        }

        int my_index = find_and_get_index(operate, my_turn) + 1;

        if(rule.at(my_index - 1) == computer_turn) {
            cout << "You Win!!!" << endl;
        } else {
            cout << "You Lose!!!" << endl;
        }
        cout << "my: " << my_turn << endl;
        cout << "computer: " << computer_turn << endl;
        cout << "************" << endl;
    }
}

void exercise_13_chess_puzzle() {
    vector<int> rices_list{1};
    int target;
    cout << "******** welcome to chess puzzle ********" << endl;
    cout << "Please enter your target: " << endl;
    cin >> target;

    int sum = 1;
    while(sum < target) {
        int last = rices_list.back();
        rices_list.push_back(last * 2);
        sum = accumulate(rices_list.begin(), rices_list.end(), 0);
    }

    cout << "target has been satisfied, the sum of rice now is: " << sum << endl;
    cout << "to finish this challenge, we use: " << rices_list.size() << " position" << endl;
}

int get_num_from_string(const string& input) {
    int index;
    vector<string> num_in_string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (input.size() > 1) {
        index = find_and_get_index(num_in_string, input);
    } else {
        index = stoi(input);
    }

    return index;
}

void exercise_12_get_num_or_string_customized_calculator() {
    string num1_string, num2_string;
    int num1, num2;
    char my_operator;

    cout << "******* welcome to my calculator *******r" << endl;
    while (cin >> num1_string >> num2_string >> my_operator) {
        num1 = get_num_from_string(num1_string);
        num2 = get_num_from_string(num2_string);
        switch (my_operator) {
            case '+': {
                double sum = num1 + num2;
                cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;
            }
                break;
            case '-': {
                double diff = num1 - num2;
                cout << "The diff of " << num1 << " and " << num2 << " is " << diff << endl;
            }
                break;
            case '*': {
                double product = num1 * num2;
                cout << "The product of " << num1 << " and " << num2 << " is " << product << endl;
            }
                break;
            case '/': {
                double quotient = num1 / num2;
                cout << "The quotient of " << num1 << " and " << num2 << " is " << quotient << endl;
            }
                break;
            case '%': {
                int modulo = (int) num1 % (int) num2;
                cout << "The modulo of " << num1 << " and " << num2 << " is " << modulo << endl;
            }
                break;
            default:
                simple_error("wrong operator");
        }
    }
}

void exercise_11_string_to_num() {
    vector<string> num_in_string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (string input; cin >> input;) {
        if (input.size() > 1) {
            int index = find_and_get_index(num_in_string, input);
            cout << index << endl;
        } else {
            int index = stoi(input);
            cout << num_in_string.at(index) << endl;
        }
    }
}

void exercise_10_customize_calculator() {
    double num1, num2;
    char my_operator;

    cout << "******* welcome to my calculator *******r" << endl;
    while (cin >> num1 >> num2 >> my_operator) {
        switch (my_operator) {
            case '+': {
                double sum = num1 + num2;
                cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;
            }
                break;
            case '-': {
                double diff = num1 - num2;
                cout << "The diff of " << num1 << " and " << num2 << " is " << diff << endl;
            }
                break;
            case '*': {
                double product = num1 * num2;
                cout << "The product of " << num1 << " and " << num2 << " is " << product << endl;
            }
                break;
            case '/': {
                double quotient = num1 / num2;
                cout << "The quotient of " << num1 << " and " << num2 << " is " << quotient << endl;
            }
                break;
            case '%': {
                int modulo = (int) num1 % (int) num2;
                cout << "The modulo of " << num1 << " and " << num2 << " is " << modulo << endl;
            }
                break;
            default:
                simple_error("wrong operator");
        }
    }
}

void exercise_9_guess_number() {
    string answer;
    int times{1};
    int guess_number{50};
    int start{0}, end{100};

    cout << "********** guess number **********" << endl;
    cout << times << ". if your number is less than " << guess_number << "?\n";
    while (cin >> answer) {
        ++times;

        if (answer == "y") {
            end = guess_number;
        }

        if (answer == "n") {
            start = guess_number;
        }

        guess_number = (start + end) / 2;

        if (end - start == 1 || end - start == 2) {
            cout << "Your number is " << guess_number << endl;
            break;
        }

        cout << times << ". if your number is less than " << guess_number << "?" << endl;
    }
}

void exercise_8_input_distance_between_two_cities() {
    vector<double> ways;

    for (double distance; cin >> distance;) {
        ways.push_back(distance);
    }

    std::sort(ways.begin(), ways.end());

    double sum = accumulate(ways.begin(), ways.end(), 0.0);
    cout << "the sum of whole ways is: " << sum << endl;
    cout << "min distance is: " << ways.at(0) << endl;
    cout << "max distance is: " << ways.at(ways.size() - 1) << endl;
    cout << "average distance is: " << sum * 1.0 / ways.size() << endl;
}

void exercise_7_calculate_mid_value() {
    vector<double> data_list;
    double lval, rval;
    for (double data; cin >> data;) {
        data_list.push_back(data);
    }

    std::sort(data_list.begin(), data_list.end());
    data_list.erase(unique(data_list.begin(), data_list.end()), data_list.end());

    if (data_list.size() % 2 == 0) {
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

    while (cin >> num >> unit) {
        check_unit(unit);

        cout << "num is: " << num << unit << endl;

        num_after_transfer_to_cm = transfer_num_to_cm(num, unit);

        if (num_after_transfer_to_cm > max) {
            max = num_after_transfer_to_cm;
            cout << "the largest so far" << endl;
        }

        if (num_after_transfer_to_cm < min) {
            min = num_after_transfer_to_cm;
            cout << "the smallest so far" << endl;
        }

        data.push_back(num_after_transfer_to_cm);
    }

    cout << "-----------" << endl;
    sort(data.begin(), data.end());
    for (double d: data) {
        cout << d << "cm" << endl;
    }
    cout << "-----------" << endl;
    cout << "min num is: " << min << "cm" << endl;
    cout << "max num is: " << max << "cm" << endl;
    cout << "sum is: " << std::accumulate(data.begin(), data.end(), 0.0) << "cm" << endl;
    cout << "total input num is: " << data.size() << endl;
    cout << "-----------" << endl;
}

void check_unit(const string &unit) {
    if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft") {
        simple_error("unit is wrong!");
    }
}

double transfer_num_to_cm(double num, const string &unit) {
    if (unit == "cm") {
        return num * 1.0;
    } else if (unit == "m") {
        return num * 100.0;
    } else if (unit == "in") {
        return num * 2.54;
    } else if (unit == "ft") {
        return transfer_num_to_cm(num * 12, "in");
    }
    return 0;
}

void exercise_1_print_two_nums_in_each_iteration() {
    double num1, num2;
    double max, min;
    while (cin >> num1 >> num2) {
        if (num1 == num2) {
            cout << "the numbers are equal" << endl;
        } else {
            max = num1 > num2 ? num1 : num2;
            min = num1 < num2 ? num1 : num2;

            if (max - min < 1.0 / 100) {
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
    for (string word; cin >> word;) {
        if (word == "end") break;
        dict.push_back(word);
    }

    for (const string &word: dict) {
        if (word == disliked) {
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
    for (int index = 0; index < num; ++index) {
        res += num;
    }
    return res;
}

void try_it_out_print_char_and_num_for_version() {
    print_char_range('a', 'z');
    print_char_range('A', 'Z');
}

void print_char_range(char start_char, char end_char) {
    for (int offset = 0; int{start_char} + offset <= int{end_char}; ++offset) {
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

#include<../lib/std_lib_facilities.h>

#include <utility>

class Name_value {
public:
    Name_value(string n, int v);

    string get_info();

    bool is_duplicate(const Name_value &nv);

private:
    string name;
    int value;
};

Name_value::Name_value(string n, int v) : name(std::move(n)), value(v) {
}

string Name_value::get_info() {
    return name.append(" ").append(to_string(value));
}

bool Name_value::is_duplicate(const Name_value &nv) {
    return this->name == nv.name;
}

class Digit {
public:
    Digit(string, int);
    void set_value(int);
    string to_string() const;
    bool is_zero() const;
private:
    string place;
    int value{0};
};

Digit::Digit(string p, int v): place(std::move(p)), value(v) {
}

void Digit::set_value(int v) {
    this->value = v;
}

string Digit::to_string() const {
    string res;
    if(value == 0) res = "";
    if(value == 1) res = ::to_string(value) + " " + place + " ";
    if(value > 1) res = ::to_string(value) + " " + place + "s ";

    return res;
}

bool Digit::is_zero() const {
    return value == 0;
}

void exercise_4_rewrite_chapter4_exercise_19_with_class();

[[noreturn]] void exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars();

vector<char> generate_rand_chars();

void test_for_generate_random_chars();

[[noreturn]] void exercise_9_get_num_and_print_in_string();

void input_nums_should_less_than_9999(const vector<char> &input_num);

vector<Digit> init_four_digits();

char get_int(char v);

bool add_and_rule_1(vector<Digit> &four_digits, int index);

void print_to_num_string(vector<Digit> &four_digits, vector<char> &input_nums);

int main() {
    // exercise_4_rewrite_chapter4_exercise_19_with_class();
    // exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars();
    // test_for_generate_random_chars();
    exercise_9_get_num_and_print_in_string();

    keep_window_open();
    return 0;
}

[[noreturn]] void exercise_9_get_num_and_print_in_string() {
    while(true) {
        vector<Digit> four_digits = init_four_digits();
        cout << "Please enter the num: ";
        vector<char> input_nums;

        while(cin) {
            input_nums_should_less_than_9999(input_nums);

            char num_char;
            cin >> num_char;

            if(num_char == ';') break;

            input_nums.push_back(num_char);
        }

        int offset = four_digits.size() - input_nums.size(); // NOLINT(cppcoreguidelines-narrowing-conversions)

        for(int index = 3; index >= offset; --index) {
            int position_in_char = index - offset;
            char v = input_nums.at(position_in_char);
            four_digits.at(index).set_value(get_int(v));
        }

        print_to_num_string(four_digits, input_nums);

    }
}

// TODO: tricky method, need to improve if have time later
void print_to_num_string(vector<Digit> &four_digits, vector<char> &input_nums) {
    // print input num
    for(char num: input_nums) {
        cout << num;
    }
    cout << " is ";

    vector<Digit> format_digit_num;
    // remove 0 value digit
    for(auto & digit : four_digits) {
        if(!digit.is_zero())
            format_digit_num.push_back(digit);
    }

    // insert "and" in format digit vector
    for(int index = 0; index < format_digit_num.size() - 1; ++index) {
        cout << format_digit_num.at(index).to_string();
        cout << "and ";

    }
    // print the last digit vector element
    cout << format_digit_num.at(format_digit_num.size() - 1).to_string();
    cout << endl;
}

char get_int(char v) { return v - '0'; }

vector<Digit> init_four_digits() {
    return {
            {"thousand", 0},
            {"hundred", 0},
            {"ten", 0},
            {"one", 0},
    };
}

void input_nums_should_less_than_9999(const vector<char> &input_num) { if(input_num.size() > 4) simple_error("cannot input num bigger than 9999"); }

void test_for_generate_random_chars() {
    for(int index = 0; index < 1000000; ++index) {
        vector<char> rand_chars = generate_rand_chars();
        std::sort(rand_chars.begin(), rand_chars.end(),
                  [](unsigned char c1, unsigned char c2){ return std::tolower(c1) < std::tolower(c2); }
        );
        for(int char_index = 1; char_index < rand_chars.size(); ++char_index) {
            if(rand_chars[char_index] == rand_chars[char_index - 1]) {
                simple_error("repeated char!");
            }
        }

        cout << index << ": " << rand_chars[0] << rand_chars[1] << rand_chars[2] << rand_chars[3] << endl;
    }

    cout << "!!! TEST SUCCESS !!!";
}

[[noreturn]] void exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars() {
    while (true) {
        vector<char> expected_chars = generate_rand_chars();
        cout << "rand chars are: " << expected_chars[0] << expected_chars[1] << expected_chars[2] << expected_chars[3] << endl;
        int correct_number{0}, correct_position{0};

        while (!(correct_number == correct_position && correct_number == expected_chars.size())) {
            // reinit number and position
            correct_number = 0;
            correct_position = 0;

            char a, b, c, d;
            vector<char> actual_chars;
            // get input
            cout << "Please enter nums you guess:\n";
            cin >> a >> b >> c >> d;
            actual_chars.push_back(a);
            actual_chars.push_back(b);
            actual_chars.push_back(c);
            actual_chars.push_back(d);

            // match numbers and positions
            for (int expected_index = 0; expected_index < expected_chars.size(); ++expected_index) {
                for (int actual_index = 0; actual_index < actual_chars.size(); ++actual_index) {
                    if (expected_chars.at(expected_index) == actual_chars.at(actual_index)) {
                        ++correct_number;

                        if (expected_index == actual_index) {
                            ++correct_position;
                        }
                    }
                }
            }

            // print
            cout << "************\n";
            cout << correct_position << " bulls, and " << correct_number - correct_position << " cows\n";
            cout << "************\n";
            cout << endl;
        }

        cout << "!!! YOU WIN !!!" << endl;
    }
}

vector<char> generate_rand_chars() {
    vector<char> res;
    res.reserve(4);
    // generate random number with time -- see README.md
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 25);

    for (int index = 0; index < 4; ++index) {
        bool not_repeated = true;
        int rand_num = dist(mt);
        char rand_char = 'a' + rand_num; // NOLINT(cppcoreguidelines-narrowing-conversions)
        for (int i = 0; i < index; ++i) {
            if (rand_char == res.at(i)) {
                not_repeated = false;
                --index;
            }
        }

        if (not_repeated) {
            res.push_back(rand_char);
        }
    }
    return res;
}

void exercise_4_rewrite_chapter4_exercise_19_with_class() {
    vector<Name_value> nv_list;
    string name;
    int score;

    cout << "Please enter names and scores:" << endl;

    while (cin >> name >> score) {
        Name_value name_value = {name, score};
        for (Name_value nv: nv_list) {
            if (nv.is_duplicate(name_value)) {
                simple_error("duplicate name");
            }
        }
        nv_list.push_back(name_value);
    }

    cout << endl;
    cout << "*******************" << endl;
    for (Name_value nv: nv_list) {
        cout << nv.get_info() << endl;
    }
}

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

void exercise_4_rewrite_chapter4_exercise_19_with_class();

[[noreturn]] void exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars();

vector<char> generate_rand_chars();

int main() {
    // exercise_4_rewrite_chapter4_exercise_19_with_class();
    exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars();

    keep_window_open();
    return 0;
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

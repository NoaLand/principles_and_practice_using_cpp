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

vector<int> generate_rand_nums();

int main() {
    // exercise_4_rewrite_chapter4_exercise_19_with_class();
    exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars();

    keep_window_open();
    return 0;
}

[[noreturn]] void exercise_8_rewrite_chapter5_bulls_and_cows_game_to_support_input_chars() {
    while (true) {
        vector<int> expected_nums = generate_rand_nums();
        int correct_number{0}, correct_position{0};

        while (!(correct_number == correct_position && correct_number == expected_nums.size())) {
            // reinit number and position
            correct_number = 0;
            correct_position = 0;

            int a, b, c, d;
            vector<int> actual_nums;
            // get input
            cout << "Please enter nums you guess:\n";
            cin >> a >> b >> c >> d;
            actual_nums.push_back(a);
            actual_nums.push_back(b);
            actual_nums.push_back(c);
            actual_nums.push_back(d);

            // match numbers and positions
            for (int expected_index = 0; expected_index < expected_nums.size(); ++expected_index) {
                for (int actual_index = 0; actual_index < actual_nums.size(); ++actual_index) {
                    if (expected_nums.at(expected_index) == actual_nums.at(actual_index)) {
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

vector<int> generate_rand_nums() {
    vector<int> res;
    res.reserve(4);
    // generate random number with time -- see README.md
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    for (int index = 0; index < 4; ++index) {
        bool not_repeated = true;
        int rand_num = dist(mt);
        for (int i = 0; i < index; ++i) {
            if (rand_num == res.at(i)) {
                not_repeated = false;
                --index;
            }
        }

        if (not_repeated) {
            res.push_back(rand_num);
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

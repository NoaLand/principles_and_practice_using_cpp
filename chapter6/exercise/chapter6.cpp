#include<../lib/std_lib_facilities.h>

#include <utility>

class Name_value {
public:
    Name_value(string n, int v);
    string get_info();
    bool is_duplicate(const Name_value& nv);
private:
    string name;
    int value;
};

Name_value::Name_value(string n, int v): name(std::move(n)), value(v) {
}

string Name_value::get_info() {
    return name.append(" ").append(to_string(value));
}

bool Name_value::is_duplicate(const Name_value& nv) {
    return this->name == nv.name;
}

void exercise_4_rewrite_chapter4_exercise_19_with_class();

int main() {
    exercise_4_rewrite_chapter4_exercise_19_with_class();
    keep_window_open();
    return 0;
}

void exercise_4_rewrite_chapter4_exercise_19_with_class() {
    vector<Name_value> nv_list;
    string name;
    int score;

    cout << "Please enter names and scores:" << endl;

    while(cin >> name >> score) {
        Name_value name_value = {name, score};
        for(Name_value nv : nv_list) {
            if(nv.is_duplicate(name_value)) {
                simple_error("duplicate name");
            }
        }
        nv_list.push_back(name_value);
    }

    cout << endl;
    cout << "*******************" << endl;
    for(Name_value nv : nv_list) {
        cout << nv.get_info() << endl;
    }
}

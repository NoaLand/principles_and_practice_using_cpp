#include "name_pairs.h"
#include "../lib/std_lib_facilities.h"

void Name_pairs::read_names(const vector<string> &n) {
    names = n;
}

void Name_pairs::read_ages() {
    cout << "enter age for each name: " << endl;

    for(const string& name: names) {
        double age;
        cout << name << ": ";
        cin >> age;
        ages.push_back(age);
    }
}

void Name_pairs::print() const {
    cout << "**********" << endl;
    cout << "NAME | AGE" << endl;

    if(names.size() != ages.size()) simple_error("name vector cannot match to age vector!");

    for(int index = 0; index < names.size(); ++index) {
        cout << names.at(index) << ", " << ages.at(index) << endl;
    }

    cout << "**********" << endl;
}

void Name_pairs::sort() {
    vector<string> temp = names;
    ::sort(names.begin(), names.end());

    for(int new_index = 0; new_index < names.size(); ++new_index) {
        for(int original_index = 0; original_index < names.size(); ++original_index) {
            if(names.at(new_index) == temp.at(original_index)
               && should_not_swap_twice(new_index, original_index)) {
                swap(ages.at(new_index), ages.at(original_index));
                break;
            }
        }
    }
}

inline bool Name_pairs::should_not_swap_twice(const int &index1, const int &index2) { return index2 > index1; }

void Name_pairs::swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

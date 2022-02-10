#include<../lib/std_lib_facilities.h>

void exercise_2_print_int_vector_with_label();

void print(const string &label, const vector<int> &iv);

int main() {
    exercise_2_print_int_vector_with_label();
    
    keep_window_open();
    return 0;
}

void exercise_2_print_int_vector_with_label() {
    string label{"this is a label"};
    vector<int> iv{1, 2, 3, 4, 5};
    print(label, iv);
}

void print(const string &label, const vector<int> &iv) {
    cout << label << endl;
    for(int i: iv) {
        cout << i << endl;
    }
}

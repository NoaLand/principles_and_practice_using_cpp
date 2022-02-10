#include<../lib/std_lib_facilities.h>

void exercise_2_print_int_vector_with_label();

void print(const string &label, const vector<int> &iv);

void exercise_3_fibonacci();

void fibonacci(int x, int y, vector<int> &fib, int n);

void exercise_5_swap_int_vector();

void swap_vector_by_creating_new_vector(const vector<int> &v1, vector<int> &v2);

void swap_vector_by_using_swap_num(vector<int> &v1);

void my_swap(int &n1, int &n2);

void exercise_6_swap_string_vector();

void swap_vector_by_creating_new_vector_string_version(const vector<string> &original, vector<string> &res);

void print_string_vector(const string &label, const vector<string> &sv);

void swap_vector_by_using_swap_num_string_version(vector<string> &v);

void my_swap_string_version(string &s1, string &s2);

int main() {
    // exercise_2_print_int_vector_with_label();
    // exercise_3_fibonacci();
    // exercise 4, the approximate int max value is 1836311903, the n in fibonacci is 46
    // exercise_5_swap_int_vector();
    exercise_6_swap_string_vector();

    keep_window_open();
    return 0;
}

void exercise_6_swap_string_vector() {
    vector<string> original_v{"1", "3", "5", "7", "9", "11"};
    vector<string> new_v;
    swap_vector_by_creating_new_vector_string_version(original_v, new_v);
    print_string_vector("new v is: ", new_v);

    vector<string> v{"1", "3", "5", "7", "9", "11"};
    swap_vector_by_using_swap_num_string_version(v);
    print_string_vector("v is: ", v);
}

void swap_vector_by_using_swap_num_string_version(vector<string> &v) {
    for(int index = 0; index < v.size() / 2; ++index) {
        my_swap_string_version(v.at(index), v.at(v.size() - index - 1));
    }
}

void my_swap_string_version(string &s1, string &s2) {
    string temp = s1;
    s1 = s2;
    s2 = temp;
}

void print_string_vector(const string &label, const vector<string> &sv) {
    cout << label << endl;
    for(string s: sv) {
        cout << s << endl;
    }
}

void swap_vector_by_creating_new_vector_string_version(const vector<string> &v1, vector<string> &v2) {
    for(int index = v1.size() - 1; index >= 0; --index) {
        v2.push_back(v1.at(index));
    }
}

void exercise_5_swap_int_vector() {
    vector<int> original_v{1, 3, 5, 7, 9};
    vector<int> new_v;
    swap_vector_by_creating_new_vector(original_v, new_v);
    print("new v is: ", new_v);

    vector<int> v{1, 3, 5, 7, 9};
    swap_vector_by_using_swap_num(v);
    print("v is: ", v);
}

void swap_vector_by_using_swap_num(vector<int> &v1) {
    for(int index = 0; index < v1.size() / 2; ++index) {
        my_swap(v1.at(index), v1.at(v1.size() - index - 1));
    }
}

void my_swap(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void swap_vector_by_creating_new_vector(const vector<int> &v1, vector<int> &v2) {
    for(int index = v1.size() - 1; index >= 0; --index) {
        v2.push_back(v1.at(index));
    }
}

void exercise_3_fibonacci() {
    int x{1}, y{1};
    int n{47};
    vector<int> v{x, y};
    fibonacci(x, y, v, n);
    const string label = "the fibs: ";
    print(label, v);
}

void fibonacci(int x, int y, vector<int> &fib, int n) {
    while(fib.size() < n) {
        int z = x + y;
        fib.push_back(z);
        fibonacci(y, z, fib, n);
    }
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

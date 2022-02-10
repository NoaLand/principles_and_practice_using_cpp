#include<../lib/std_lib_facilities.h>

void exercise_2_print_int_vector_with_label();

void print(const string &label, const vector<int> &iv);

void exercise_3_fibonacci();

void fibonacci(int x, int y, vector<int> &fib, int n);

int main() {
    // exercise_2_print_int_vector_with_label();
    exercise_3_fibonacci();
    
    keep_window_open();
    return 0;
}

void exercise_3_fibonacci() {
    int x{1}, y{1};
    int n{20};
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

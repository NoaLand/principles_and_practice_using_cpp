#include <../lib/std_lib_facilities.h>

void try_it_out_1();

int area(int length, int width);

void try_it_out_2();

void exercise_1_to_25_get_used_with_compile_err();

void my_code();

int main() {
    // try_it_out_1();
    // try_it_out_2();
    exercise_1_to_25_get_used_with_compile_err();

    keep_window_open();
    return 0;
}

void exercise_1_to_25_get_used_with_compile_err() {
    try {
        // your code here
        my_code();
    } catch(exception& e) {
        cerr << "error: " << e.what() << endl;
    } catch(...) {
        cerr << "Oops: unknown exception!" << endl;
    }
}

void my_code() {
    // 1. Cout << "Success!\n";  -- "Cout" is wrong, it should be "cout"
    // cout << "Success!\n";

    // 2. cout << "Success!\n; -- Lost " symbol
    cout << "Success!\n";
}

void try_it_out_2() {
    // int x0 = arena(7); // function "arena(int)" not declared
    // int x1 = area(7);  // number of param is not matched
    // int x2 = area("seven", 2); // the type of first param is not matched
}

void try_it_out_1() {
    // int s1 = area(7;   // symbol ) lost
    // int s2 = area(7)   // symbol ; lost
    // Int s3 = area(7);  // Int is not a type
    // int s4 = area('7); // symbol ' lost
}

int area(int length, int width) {
    return length * width;
}

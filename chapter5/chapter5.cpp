#include <../lib/std_lib_facilities.h>

void try_it_out_1();

int area(int length, int width);

int main() {
    try_it_out_1();

    keep_window_open();
    return 0;
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

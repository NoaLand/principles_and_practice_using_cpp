#include "my.h"
#include<../lib/std_lib_facilities.h>

int foo;

void print_foo() {
    cout << "foo: " << foo << endl;
}

void print(const int& i) {
    cout << "i: " << i << endl;
}

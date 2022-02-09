#include<../lib/std_lib_facilities.h>

namespace X {
    int var;
    void print() {
        cout << "X::var: " << var << endl;
    }
}

namespace Y {
    int var;
    void print() {
        cout << "Y::var: " << var << endl;
    }
}

namespace Z {
    int var;
    void print() {
        cout << "Z::var: " << var << endl;
    }
}

int main() {
    X::var = 7; // set 7 to var in X
    X::print(); // print var in X
    using namespace Y;
    var = 9; // set 9 to var in Y
    print(); // print var in Y
    {
        using Z::var;
        using Z::print;
        var == 11; // set 11 to var in Z
        print(); // print var in Z
    }
    print(); // print var in Y, since `using namespace Y`
    X::print(); // print var in X

    keep_window_open();
    return 0;
}

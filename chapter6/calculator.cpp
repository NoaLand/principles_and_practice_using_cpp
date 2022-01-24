#include<../lib/std_lib_facilities.h>

int main() {
    cout << "Please enter expression (we can handle + and -):";
    int lval{0}, rval, res{0};
    char op;
    cin >> lval >> op >> rval;

    if(op == '+')
        res = lval + rval;
    else if(op == '-')
        res = lval - rval;

    cout << "Result: " << res << endl;

    keep_window_open();
    return 0;
}

#include<../lib/std_lib_facilities.h>

int main() {
    cout << "Please enter expression (we can handle + and -):\n";
    cout << "add an x to end expression (e.g., 1 + 2 * 3 x):\n";
    int lval{0}, rval;
    cin >> lval;
    if(!cin) simple_error("no first operand");
    for(char op; cin >> op;) {
        if(op != 'x') cin >> rval;
        if(!cin) simple_error("no second operand");
        switch(op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result: " << lval << endl;
                keep_window_open();
                return 0;
        }
    }

    simple_error("bad expression");
}

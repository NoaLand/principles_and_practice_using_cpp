#include "../../lib/std_lib_facilities.h"

class Token {
public:
    Token(char ch)    // make a Token from a char
            :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
            :kind(ch), value(val) { }
    char kind;        // what kind of token
    double value;     // for numbers: a value
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream(): full(false), buffer(0) {
}

void Token_stream::putback(Token t) {
    if (full) simple_error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
        case '=':    // for "print"
        case 'x':    // for "quit"
        case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
            return {ch};        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return {'8', val};   // let '8' represent "a number"
        }
        default:
            simple_error("Bad token");
    }
}

Token_stream ts;

double expression();

double factorial(double left);

double sub_primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if(t.kind != ')') simple_error("')' expected");
            return d;
        }
        case '{': {
            double d = expression();
            t = ts.get();
            if(t.kind != '}') simple_error("'}' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            simple_error("primary expected");
    }
}

double primary() {
    double left = sub_primary();
    Token t = ts.get();

    while(true) {
        switch(t.kind) {
            case '!': {
                left = factorial(left);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);     // put t back into the token stream
                return left;
        }
    }
}

double factorial(double left) {
    int integer_left = (int)left;
    // will get into this statement when left value is a double
    if(integer_left != left) simple_error("cannot handle double in factorial");
    if(integer_left == 0){
        left = 1;
    } else {
        int res = 1;
        for(int index = 1; index <= left; ++index) {
            res *= index;
        }
        left = res;
    }
    return left;
}

double term() {
    double left = primary();
    Token t = ts.get();

    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0) simple_error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);     // put t back into the token stream
                return left;
        }
    }
}

double expression() {
    double left = term();
    Token t = ts.get();

    while(true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left += term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

int main() {
    try {
        double val{0};
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Welcome to our simple calculator." << endl;
        cout << "Please enter expressions using floating-point numbers." << endl;
        cout << "You can use +, -, *, /, % to calculate." << endl;
        cout << "1. By input '=' to print the result of expression you have entered." << endl;
        cout << "2. By input 'x' to exit this calculator." << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'x') break;
            if (t.kind == '=') {
                cout << "=" << val << '\n';
                continue;
            }
            else {
                ts.putback(t);
            }
            val = expression();
        }
        keep_window_open();
    }
    catch (exception &e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

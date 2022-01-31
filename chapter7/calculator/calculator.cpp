#include "../../lib/std_lib_facilities.h"

static const char number = '8';

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
        case 'P': case 'C': case ',': case '%':
            return {ch};        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return {number, val};   // let '8' represent "a number"
        }
        default:
            simple_error("Bad token");
    }
}

Token_stream ts;

double expression();

double factorial(double left);

double permutation(double a, double b);

double combination(double a, double b);

double sub_primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '+':
            return sub_primary();
        case '-':
            return -sub_primary();
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
        case number:
            return t.value;
        case 'P': {
            t = ts.get();
            if(t.kind != '(') simple_error("Permutation should has () statement");
            double a = expression();
            t = ts.get();
            if(t.kind != ',') simple_error("there should be a ',' after expression A");
            double b = expression();
            t = ts.get();
            if(t.kind != ')') simple_error("Permutation should has () statement");

            return permutation(a, b);
        }
        case 'C': {
            t = ts.get();
            if(t.kind != '(') simple_error("Combination should has () statement");
            double a = expression();
            t = ts.get();
            if(t.kind != ',') simple_error("there should be a ',' after expression A");
            double b = expression();
            t = ts.get();
            if(t.kind != ')') simple_error("Combination should has () statement");

            return combination(a, b);
        }
        default:
            simple_error("primary expected");
    }
}

double combination(double a, double b) { return permutation(a, b) / factorial(b); }

double permutation(double a, double b) { return factorial(a) / factorial(a - b); }

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
        left = 1; } else { int res = 1;
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
                if(d == 0) simple_error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary();
                if(d == 0) simple_error("divide by zero");
                left = left - d * (int)(left / d);
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
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Welcome to our simple calculator." << endl;
        cout << "Please enter expressions using floating-point numbers." << endl;
        cout << "1. You can use +, -, *, /, % to calculate." << endl;
        cout << "2. You can calculate Permutation by inputting P(a, b) " << endl;
        cout << "3. You can calculate Combination by inputting C(a, b) " << endl;
        cout << "4. By inputting '=' to print the result of expression you have entered." << endl;
        cout << "5. By inputting 'x' to exit this calculator." << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        while (cin) {
            cout << "> ";
            Token t = ts.get();

            while(t.kind == '=') t=ts.get();
            if(t.kind == 'x') {
                keep_window_open();
                return 0;
            }
            ts.putback(t);
            cout << "= " << expression() << endl;
        }
        keep_window_open();
        return 0;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        cout << "Please enter the character ~~ to close the window." << endl;
        keep_window_open("~~");
        return 1;
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

#include <utility>

#include "../../lib/std_lib_facilities.h"

const char name = 'a';

const char let = 'L';
const char declkey = '#';

const char square_root = 'S';
const string sqrt_key = "sqrt";

const char power = 'p';
const string power_key = "pow";

static const char quit = 'Q';
const string quit_key = "exit";

static const char number = '8';
static const char print = ';';
static const char *const prompt = "> ";
static const char *const result = "= ";

static const char assignment = '=';

int narrow_cast_to_int(double d) {
    int d_int = (int) d;
    // will get into this statement when left value is a double
    if(d != d_int) simple_error("is not integer");
    
    return d_int;
}

class Variable {
public:
    string name;
    double value;
    bool is_const;
};

vector<Variable> var_table;

double get_value(const string& s) {
    for(const Variable& v: var_table) {
        if(v.name == s) {
            return v.value;
        }
    }
    simple_error("get: undefined variable " + s);
}

void set_value(const string& s, double d) {
    for(Variable& v: var_table) {
        if(v.name == s) {
            if(!v.is_const) {
                v.value = d;
                return;
            } else {
                simple_error("set: variable is const, cannot change");
            }
        }
    }
    simple_error("set: undefined variable " + s);
}

class Token {
public:
    Token(char ch)
            :kind(ch), value(0) {}
    Token(char ch, double val)
            :kind(ch), value(val) {}
    Token(char ch, string n)
            : kind(ch), name(std::move(n)) {}
    char kind;
    double value;
    string name;
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c);
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
        case print:
        case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
        case 'P': case 'C': case ',': case '%': case assignment:
            return {ch};
        case declkey:
            return {let};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': {
            cin.putback(ch);
            double val;
            cin >> val;
            return {number, val};
        }
        default:
            if(isalpha(ch)) {
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
                cin.putback(ch);
                if(s == quit_key) return {quit};
                if(s == sqrt_key) return {square_root};
                if(s == power_key) return {power};
                return {name, s};
            }
            simple_error("Bad token");
    }
}

void Token_stream::ignore(char c) {
    if(full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while(cin >> ch)
        if(ch == c) return;
}

Token_stream ts;

double expression();

bool is_declared(string var) {
    for(Variable v: var_table) {
        if(v.name == var)
            return true;
    }

    return false;
}

double define_name(string var, double val, bool is_const = false) {
    if(is_declared(var)) simple_error(var + " declared twice");
    var_table.push_back({var, val, is_const});

    return val;
}

double declaration() {
    Token t = ts.get();
    if(t.kind != name) simple_error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != assignment) simple_error("= missing in declaration of " + var_name);

    double d = expression();
    define_name(var_name, d);

    return d;
}

double statement() {
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

double factorial(double left);

double permutation(double a, double b);

double combination(double a, double b);

void calculate();

void clean_up_mess();

void variable_predefine();

double my_pow(double x, int i);

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
        case square_root: {
            t = ts.get();
            if(t.kind != '(') simple_error("Combination should has () statement");
            double a = expression();
            if(a < 0) simple_error("number should not less than zero, when try to calculate square root");
            t = ts.get();
            if(t.kind != ')') simple_error("Combination should has () statement");

            return sqrt(a);
        }
        case power: {
            t = ts.get();
            if(t.kind != '(') simple_error("Power calculation should has () statement");
            double x = expression();
            t = ts.get();
            if(t.kind != ',') simple_error("there should be x ',' after expression A");
            int i = narrow_cast_to_int(expression());
            t = ts.get();
            if(t.kind != ')') simple_error("Power calculation should has () statement");

            return my_pow(x, i);
        }
        case name: {
            Token symbol = ts.get();
            if(symbol.kind == assignment) {
                double v = expression();
                set_value(t.name, v);
                return v;
            } else {
                ts.putback(symbol);
                return get_value(t.name);
            }
        }
        default:
            simple_error("sub-primary expected");
    }
}

double my_pow(double x, int i) {
    double res{1};
    for(int index = 0; index < i; ++index) {
        res *= x;
    }

    return res;
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
                ts.putback(t);
                return left;
        }
    }
}

double factorial(double left) {
    int integer_left = narrow_cast_to_int(left);
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
                ts.putback(t);
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
        variable_predefine();

        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Welcome to our simple calculator." << endl;
        cout << "Please enter expressions using floating-point numbers." << endl;
        cout << "1. You can use +, -, *, /, % to calculate." << endl;
        cout << "2. You can calculate Permutation by inputting P(a, b)." << endl;
        cout << "3. You can calculate Combination by inputting C(a, b)." << endl;
        cout << "4. You can declare a variable by using `# x = 2.4;`." << endl;
        cout << "5. You can calculate power by using `pow(3.2, 2);`." << endl;
        cout << "6. You can calculate square root of a number by inputting `sqrt(4.0);`" << endl;
        cout << "7. By inputting ';' to print the result of expression you have entered." << endl;
        cout << "8. By inputting 'exit' to exit this calculator." << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        calculate();
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

void variable_predefine() {
    define_name("pi", 3.1415926535, true);
    define_name("e", 2.7182818284, true);
    define_name("k", 1000);
}

void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();

            while(t.kind == print) t = ts.get();
            if(t.kind == quit) {
                return;
            }
            ts.putback(t);
            cout << result << statement() << endl;
        } catch(exception& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

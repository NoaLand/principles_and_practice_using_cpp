#include <utility>

#include "../../lib/std_lib_facilities.h"

const char name = 'a';

const char let = 'L';
const char declkey = '#';

const char cons = 'C';
const string const_key = "const"; // NOLINT(cert-err58-cpp)

const char square_root = 'S';
const string sqrt_key = "sqrt"; // NOLINT(cert-err58-cpp)

const char power = 'p';
const string power_key = "pow"; // NOLINT(cert-err58-cpp)

static const char quit = 'Q';
const string quit_key = "quit"; // NOLINT(cert-err58-cpp)

static const char help = 'H';
static string help_key = "help"; // NOLINT(cert-err58-cpp)

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

class Symbol_table {
public:
    double get_value(const string&);
    void set_value(const string&, double);
    bool is_declared(const string&);
    double define_name(const string&, double, bool);
private:
    vector<Variable> var_table;
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
double Symbol_table::get_value(const string& s) {
    for(const Variable& v: var_table) {
        if(v.name == s) {
            return v.value;
        }
    }
    simple_error("get: undefined variable " + s);
}
#pragma clang diagnostic pop

void Symbol_table::set_value(const string& s, double d) {
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

bool Symbol_table::is_declared(const string& var) {
    return std::any_of(
            var_table.begin(),
            var_table.end(),
            [var](const Variable& v){return v.name == var;}
            );
}

double Symbol_table::define_name(const string& var, double val, bool is_const = false) {
    if(is_declared(var)) simple_error(var + " declared twice");
    var_table.push_back({var, val, is_const});

    return val;
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
    double value{};
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
    buffer = std::move(t);
    full = true;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
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
                if(s == const_key) return {cons};
                if(s == help_key) return {help};
                return {name, s};
            }
            simple_error("Bad token");
    }
}
#pragma clang diagnostic pop

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

double expression(Token_stream&, Symbol_table&);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma clang diagnostic ignored "-Wreturn-type"
double declaration(Token_stream& ts, Symbol_table& st, bool is_const = false) {
    Token t = ts.get();
    switch(t.kind) {
        case name: {
            string var_name = t.name;

            Token t2 = ts.get();
            if(t2.kind != assignment) simple_error("= missing in declaration of " + var_name);

            double d = expression(ts, st);
            st.define_name(var_name, d, is_const);

            return d;
        }
        case cons:
            return declaration(ts, st, true);
        default:
            simple_error("wrong declaration");
    }
}
#pragma clang diagnostic pop

double statement(Token_stream& ts, Symbol_table& st) {
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration(ts, st);
        default:
            ts.putback(t);
            return expression(ts, st);
    }
}

double factorial(double left);

double permutation(double a, double b);

double combination(double a, double b);

void calculate(Token_stream&, Symbol_table&);

void clean_up_mess(Token_stream&);

void variable_predefine(Symbol_table&);

double my_pow(double x, int i);

void help_info();

void welcome_info();

void init_calculator(Symbol_table&);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma clang diagnostic ignored "-Wreturn-type"
double sub_primary(Token_stream& ts, Symbol_table& st) {
    Token t = ts.get();
    switch (t.kind) {
        case '+':
            return sub_primary(ts, st);
        case '-':
            return -sub_primary(ts, st);
        case '(': {
            double d = expression(ts, st);
            t = ts.get();
            if(t.kind != ')') simple_error("')' expected");
            return d;
        }
        case '{': {
            double d = expression(ts, st);
            t = ts.get();
            if(t.kind != '}') simple_error("'}' expected");
            return d;
        }
        case number:
            return t.value;
        case 'P': {
            t = ts.get();
            if(t.kind != '(') simple_error("Permutation should has () statement");
            double a = expression(ts, st);
            t = ts.get();
            if(t.kind != ',') simple_error("there should be a ',' after expression A");
            double b = expression(ts, st);
            t = ts.get();
            if(t.kind != ')') simple_error("Permutation should has () statement");

            return permutation(a, b);
        }
        case 'C': {
            t = ts.get();
            if(t.kind != '(') simple_error("Combination should has () statement");
            double a = expression(ts, st);
            t = ts.get();
            if(t.kind != ',') simple_error("there should be a ',' after expression A");
            double b = expression(ts, st);
            t = ts.get();
            if(t.kind != ')') simple_error("Combination should has () statement");

            return combination(a, b);
        }
        case square_root: {
            t = ts.get();
            if(t.kind != '(') simple_error("Combination should has () statement");
            double a = expression(ts, st);
            if(a < 0) simple_error("number should not less than zero, when try to calculate square root");
            t = ts.get();
            if(t.kind != ')') simple_error("Combination should has () statement");

            return sqrt(a);
        }
        case power: {
            t = ts.get();
            if(t.kind != '(') simple_error("Power calculation should has () statement");
            double x = expression(ts, st);
            t = ts.get();
            if(t.kind != ',') simple_error("there should be x ',' after expression A");
            int i = narrow_cast_to_int(expression(ts, st));
            t = ts.get();
            if(t.kind != ')') simple_error("Power calculation should has () statement");

            return my_pow(x, i);
        }
        case name: {
            Token symbol = ts.get();
            if(symbol.kind == assignment) {
                double v = expression(ts, st);
                st.set_value(t.name, v);
                return v;
            } else {
                ts.putback(symbol);
                return st.get_value(t.name);
            }
        }
        default:
            simple_error("sub-primary expected");
    }
}
#pragma clang diagnostic pop

double my_pow(double x, int i) {
    double res{1};
    for(int index = 0; index < i; ++index) {
        res *= x;
    }

    return res;
}

double combination(double a, double b) { return permutation(a, b) / factorial(b); }

double permutation(double a, double b) { return factorial(a) / factorial(a - b); }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
double primary(Token_stream& ts, Symbol_table& st) {
    double left = sub_primary(ts, st);
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
#pragma clang diagnostic pop

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

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
double term(Token_stream& ts, Symbol_table& st) {
    double left = primary(ts, st);
    Token t = ts.get();

    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary(ts, st);
                t = ts.get();
                break;
            case '/': {
                double d = primary(ts, st);
                if(d == 0) simple_error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary(ts, st);
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
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
double expression(Token_stream& ts, Symbol_table& st) {
    double left = term(ts, st);
    Token t = ts.get();

    while(true) {
        switch (t.kind) {
            case '+': {
                left += term(ts, st);
                t = ts.get();
                break;
            }
            case '-':
                left += term(ts, st);
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
#pragma clang diagnostic pop

int main() {
    try {
        Token_stream ts;
        Symbol_table st;

        init_calculator(st);

        calculate(ts, st);

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

void init_calculator(Symbol_table& st) {
    variable_predefine(st);
    welcome_info();
}

void welcome_info() {
    cout << "********************* WELCOME *********************" << endl;
    cout << "************** Press 'help' get help **************" << endl;
}

void help_info() {
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
    cout << "8. By inputting 'help' to get help info of this calculator." << endl;
    cout << "9. By inputting 'quit' to exit this calculator." << endl;
    cout << "------------------------------------------------------------------------------" << endl;
}

void variable_predefine(Symbol_table& st) {
    st.define_name("pi", 3.1415926535, true);
    st.define_name("e", 2.7182818284, true);
    st.define_name("k", 1000);
}

void calculate(Token_stream& ts, Symbol_table& st) {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();

            while(t.kind == print) t = ts.get();
            if(t.kind == quit) {
                return;
            }
            if(t.kind == help) {
                help_info();
                continue;
            }
            ts.putback(t);
            cout << result << statement(ts, st) << endl;
        } catch(exception& e) {
            cerr << e.what() << endl;
            clean_up_mess(ts);
        }
    }
}

void clean_up_mess(Token_stream& ts) {
    ts.ignore(print);
}

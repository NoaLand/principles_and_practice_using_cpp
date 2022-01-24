#include<../lib/std_lib_facilities.h>

class Token {
public:
    char kind;
    double value;
    Token(char ch): kind(ch), value(0) {}
    Token(char ch, double val): kind(ch), value(val) {}
};


class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
        :full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) simple_error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case ';':    // for "print"
        case 'q':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8', val);   // let '8' represent "a number"
        }
        default:
            simple_error("Bad token");
    }
}

Token_stream ts;        // provides get() and putback()

Token get_token();
Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        //not yet   case ';':    // for "print"
        //not yet   case 'q':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
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

double expression();

double primary();

double term() {
    double left = primary();
    Token t = ts.get();
    while(true) {
        switch(t.kind) {
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
//            case '%':
//                left %= primary();
//                t = get_token();
//                break;
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
        switch(t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch(t.kind) {
        case '(': {
            double d = expression();
            t = get_token();
            if(t.kind != ')') simple_error("')' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            simple_error("primary expected");
    }
}

int main() {
    try {
        double val{0};
        while(cin) {
            Token t = ts.get();

            if(t.kind == 'q') break;
            if(t.kind == ';')
                cout << val << endl;
            else
                ts.putback(t);
            val = expression();
        }
        keep_window_open();
    } catch(exception& e) {
        cerr << e.what() << endl;
        keep_window_open();
        return 1;
    } catch(...) {
        cerr << "exception" << endl;
        keep_window_open();
        return 2;
    }
}

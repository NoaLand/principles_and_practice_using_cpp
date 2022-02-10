#include "token.h"
#include "../constant.h"

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

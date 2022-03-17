#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_TOKEN_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_TOKEN_H
#include "../../../../lib/std_lib_facilities.h"
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
    Token_stream(istream&);
    Token get();
    void putback(Token t);
    void ignore(char c);
    istream& get_istream();
private:
    bool full;
    Token buffer;
    istream& is;
};
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_TOKEN_H

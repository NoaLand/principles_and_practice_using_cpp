/*
 * This is the implement for english grammar exercise, according to the design in English.readme.md
 *
 * Token Type Map:
 *      1. Conjunction -> 'c'
 *      2. Determiner -> 'd'
 *      3. NounDic -> 'n'
 *      4. Verb -> 'v'
 *
 * Define:
 *      * `Token` is a word, or ".", so basically, we define Token has a `type` and `value` field
 *        And it should be similar to the design in calculator. Quit by type in `q`, and get result
 *        by type in `.`, and the result should be "OK" or "not OK".
 *
 *      * `Token_stream` is similar to token_stream in calculator as well, and has `get` and `putback`
 *        method. And add function is_word_type_correct to make sure when I got wrong answer, I will
 *        put it back to buffer.
 */
#include<../lib/std_lib_facilities.h>

#include <utility>

class Token {
public:
    char type{};
    string value;
};

class Token_stream {
public:
    Token get();
    void putback(Token);
    bool is_word_type_correct(const Token&, char);
private:
    bool full{false};
    Token buffer;
};

Token Token_stream::get() {
    if(full) {
        full = false;
        return buffer;
    }

    string word;
    cin >> word;

    if(word == "." || word == "q") {
        return {word[0]};
    } else if(word == "and" || word == "or" || word == "but") {
        return {'c', word};
    } else if(word == "the") {
        return {'d', word};
    } else if(word == "birds" || word == "fish" || word == "C++") {
        return {'n', word};
    } else if(word == "rules" || word == "fly" || word == "swim") {
        return {'v', word};
    } else {
        simple_error("Bad token");
    }
}

void Token_stream::putback(Token token) {
    if (full) simple_error("putback() into a full buffer");
    full = true;
    buffer = std::move(token);
}

bool Token_stream::is_word_type_correct(const Token& token, char type) {
    if(token.type == type) {
        return true;
    } else {
        this->putback(token);

        return false;
    }
}

Token_stream ts;

bool is_noun_dic() {
    Token noun_dic = ts.get();

    return ts.is_word_type_correct(noun_dic, 'n');
}

bool is_determiner() {
    Token determiner = ts.get();

    return ts.is_word_type_correct(determiner, 'd');
}

bool is_noun() {
    bool is_only_noun = is_noun_dic();
    bool is_the_determiner = is_determiner();
    bool is_noun = is_noun_dic();

    return is_only_noun || (is_the_determiner && is_noun);
}

bool is_verb() {
    Token verb = ts.get();

    return ts.is_word_type_correct(verb, 'v');
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
bool is_sentence() {
    bool noun = is_noun();
    bool verb = is_verb();
    bool res = noun && verb;

    if(!res) {
        return false;
    }

    Token word = ts.get();
    while(true) {
        switch(word.type) {
            case 'c':
                res = res && is_sentence();
                word = ts.get();
                break;
            default:
                ts.putback(word);
                return res;
        }
    }

}
#pragma clang diagnostic pop

int main() {
    try{
        bool res{false};
        while(cin) {
            Token t = ts.get();

            if(t.type == 'q') break;
            if(t.type == '.') {
                cout << (res ? "OK" : "not OK") << endl;
                continue;
            } else {
                ts.putback(t);
            }
            res = is_sentence();
        }

        keep_window_open();
    } catch(exception& e) {
        cerr << "error: " << e.what() << endl;
        keep_window_open();
        return 1;
    } catch(...) {
        cerr << "Oops! Unknown exception!" << endl;
        keep_window_open();
        return 2;
    }
}

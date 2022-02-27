#include "../lib/std_lib_facilities.h"

void end_of_loop(istream& ist, char term, const string& message) {
    if(ist.fail()) {
        ist.clear();
        char ch;
        if(ist >> ch && ch == term) return;
        simple_error(message);
    }
}

int main() {
    for(int var; cin >> var;) {
    }

    end_of_loop(cin, '|', "bad termination of file.");

    keep_window_open();
    return 0;
}
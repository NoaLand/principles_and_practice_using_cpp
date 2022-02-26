#include "../lib/std_lib_facilities.h"

void fill_vector(istream& ist, vector<int>& v, char terminator) {
    for(int i; ist >> i;) v.push_back(i);
    if(ist.eof()) return;

    ist.clear();

    char c;
    ist >> c;

    if(c != terminator) {
        ist.putback(c);
        ist.clear(ios_base::failbit);
    }
}
#include "../lib/std_lib_facilities.h"

int main() {
    cout << "Please enter input file 1: ";
    string iname1;
    cin >> iname1;

    cout << "Please enter input file 2: ";
    string iname2;
    cin >> iname2;

    cout << "Please enter output file: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if(!ost) simple_error("wrong ost");

    ifstream ist;
    ist.open(iname1, ifstream::in);
    vector<string> word_list;
    string words;
    while(ist >> words) {
        word_list.push_back(words);
    }
    ist.close();

    ist.open(iname2, ifstream::in);
    while(ist >> words) {
        word_list.push_back(words);
    }
    ist.close();

    sort(word_list.begin(), word_list.end());

    for(string w : word_list) {
        ost << w << " ";
    }
    ost << flush;
    ost.close();

    cout << "finish" << endl;

    keep_window_open();
    return 0;
}

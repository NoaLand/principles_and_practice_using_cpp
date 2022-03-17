#include "../lib/std_lib_facilities.h"

int main() {
    cout << "Please enter input file 1: ";
    string iname1;
    cin >> iname1;
    ifstream ist1{iname1};
    if(!ist1) simple_error("wrong ist1");

    cout << "Please enter input file 2: ";
    string iname2;
    cin >> iname2;
    ifstream ist2{iname2};
    if(!ist2) simple_error("wrong ist2");

    cout << "Please enter output file: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if(!ost) simple_error("wrong ost");

    vector<string> word_list;
    string words;
    while(ist1 >> words) {
        word_list.push_back(words);
    }

    while(ist2 >> words) {
        word_list.push_back(words);
    }

    sort(word_list.begin(), word_list.end());

    for(string w : word_list) {
        ost << w << endl;
    }

    cout << "finish" << endl;

    keep_window_open();
    return 0;
}

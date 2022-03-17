#include "../lib/std_lib_facilities.h"

int main() {
    cout << "Please enter output file: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if(!ost) simple_error("wrong ost");

    cout << "Please enter input file 1: ";
    string iname1;
    cin >> iname1;
    ifstream ist1{iname1};
    if(!ist1) simple_error("wrong ist1 in input file 1");
    string contains;
    while(ist1 >> contains) {
        ost << contains << endl;
    }

    cout << "Please enter input file 2: ";
    string iname2;
    cin >> iname2;
    ifstream ist2{iname2};
    if(!ist2) simple_error("wrong ist2 in input file 2");
    while(ist2 >> contains) {
        ost << contains << endl;
    }

    cout << "finish" << endl;

    keep_window_open();
    return 0;
}

#include "../lib/std_lib_facilities.h"

int main() {
    cout << "please enter your input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) simple_error("wrong ist");

    int sum{0};
    for(int num; ist >> num;) {
        sum += num;
    }

    cout << "sum is: " << sum << endl;
}

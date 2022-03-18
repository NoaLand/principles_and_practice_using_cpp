#include "../lib/std_lib_facilities.h"

int main() {
    cout << "Please enter input file: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) simple_error("wrong ist");

    vector<int> num_vec;
    for(char num_char; ist >> num_char;) {
        if(isdigit(num_char)) {
            ist.putback(num_char);
            int num;
            ist >> num;
            num_vec.push_back(num);
        }
    }

    int sum{0};
    for(int n : num_vec) {
        sum += n;
    }

    cout << "sum: " << sum << endl;

    keep_window_open();
    return 0;
}

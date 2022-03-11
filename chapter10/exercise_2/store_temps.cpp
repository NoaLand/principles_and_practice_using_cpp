#include "../lib/std_lib_facilities.h"

struct Reading {
    int hour{-1};
    double temperature{-999};
};

istream& operator>>(istream& is, Reading& r) {
    int hour;
    double temperature;
    is >> hour >> temperature;
    if(!is) {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    if(hour < 0 || hour > 23) simple_error("wrong hour format: " + to_string(hour));

    r = {hour, temperature};

    return is;
}

int main() {
    cout << "please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) simple_error("wrong ist");

    vector<Reading> readings;
    for(Reading r; ist >> r;) {
        readings.push_back(r);
    }

    cout << "OUTPUT" << endl;
    for(Reading r : readings) {
        cout << r.hour << " " << r.temperature << endl;
    }

    keep_window_open();
    return 0;
}

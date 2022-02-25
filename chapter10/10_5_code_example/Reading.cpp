#include "../lib/std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
};

int main() {
    cout << "path: " << std::__fs::filesystem::current_path().string() << endl;
    cout << "please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) {
        if(ist.bad()) simple_error("ist is bad!");
        if(ist.eof()) {
            cout << "ist is in eof state";
            ist.clear();
        }
        if(ist.fail()) {
            ist.clear();
        }
    }

    cout << "path: " << std::__fs::filesystem::current_path().string() << endl;
    cout << "please enter output file name: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if(!ost) simple_error("can't open output file " + oname);

    vector<Reading> temps;
    int hour;
    double temperature;
    while(ist >> hour >> temperature) {
        if(hour < 0 || hour > 23) simple_error("hour out of range");
        temps.push_back({hour, temperature});
    }

    for(Reading r : temps) {
        ost << '(' << r.hour << ',' << r.temperature << ')' << endl;
    }

    keep_window_open();
    return 0;
}

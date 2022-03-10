#include "Point.h"

int main() {
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) {
        if(ist.bad()) simple_error("ist is bad");
        if(ist.fail()) {
            ist.unget();
            ist.clear(ios_base::failbit);
        }
        if(ist.eof()) {
            ist.clear();
        }
    }

    vector<Point> points;
    for(Point p; ist >> p;) {
        points.push_back(p);
    }

    cout << "Points are: " << endl;
    for(Point p : points) {
        cout << p;
    }
}

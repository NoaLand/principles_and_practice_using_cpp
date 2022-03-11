#include "Point.h"

int main() {
    cout << "please enter your output file name: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if(!ost) simple_error("wrong ost");

    cout << "Please enter 7 points by using the following format (x, y): " << endl;

    vector<Point> original_points;

    for(int index = 0; index < 7; ++index) {
        Point p;
        cout << index + 1 << ": ";
        cin >> p;
        original_points.push_back(p);
    }

    cout << "Your input: " << endl;
    for(Point p : original_points) {
        cout << p;
    }
    cout << "FINISH" << endl;

    cout << endl;

    cout << "Print to file..." << endl;
    for(Point p : original_points) {
        ost << p;
    }
    cout << "FINISH" << endl;
}
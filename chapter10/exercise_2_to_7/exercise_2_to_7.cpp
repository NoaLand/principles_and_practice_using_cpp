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

    cout << "start reading file" << endl;
    vector<Point> processed_points;
    ifstream ist{oname};
    if(!ist) simple_error("wrong ist");
    for(Point p; ist >> p;) {
        processed_points.push_back(p);
    }

    cout << "Processed points are: " << endl;
    for(Point p : processed_points) {
        cout << p;
    }

    cout << endl;

    cout << "Compare vectors..." << endl;
    if(original_points.size() != processed_points.size()) cout << "Something's wrong!" << endl;
    for(int index = 0; index < original_points.size(); ++index) {
        if(original_points[index] != processed_points[index]) {
            cout << "Something's wrong!" << endl;
        }
    }
    cout << "FINISH COMPARE" << endl;
}
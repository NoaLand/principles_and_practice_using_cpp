#include "Point.h"

int main() {
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
}
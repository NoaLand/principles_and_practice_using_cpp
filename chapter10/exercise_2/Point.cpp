#include "Point.h"

Point::Point(double xx, double yy): x{xx}, y{yy} {
}

istream& operator>>(istream& ist, Point& p) {
    char left, separator, right;
    double x, y;
    ist >> left >> x >> separator >> y >> right;
    if(!ist) {
        ist.unget();
        ist.clear(ios_base::failbit);
        return ist;
    }
    if(left != '(' || separator != ',' || right != ')') {
        simple_error("wrong format");
    }

    p = {x, y};

    return ist;
}

ostream& operator<<(ostream& ost, const Point& p) {
    return ost << "(" << p.x << ", " << p.y << ")" << endl;
}
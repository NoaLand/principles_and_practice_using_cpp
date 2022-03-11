#include "Point.h"

istream &operator>>(istream &is, Point& p) {
    double x;
    char separator;
    double y;
    is >> x;

    is >> separator;
    if(separator != ',' && !is.eof()) {
        simple_error("wrong format");
    }

    is >> y;

    p = {x, y};

    return is;
}

ostream &operator<<(ostream &os, const Point &p) {
    return os << "(" << p.x << ", " << p.y << ")" << endl;
}

Point::Point(double xx, double yy): x{xx}, y{yy} {
}

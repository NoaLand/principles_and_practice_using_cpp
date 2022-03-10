#include "Point.h"

istream &operator>>(istream &is, Point& p) {
    double x;
    char separator;
    double y;
    is >> x >> separator >> y;
    if(separator != ',') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    p = {x, y};

    return is;
}

ostream &operator<<(ostream &os, const Point &p) {
    return os << "(" << p.x << ", " << p.y << ")" << endl;
}

Point::Point(double xx, double yy): x{xx}, y{yy} {
}

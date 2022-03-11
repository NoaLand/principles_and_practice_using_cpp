#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_POINT_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_POINT_H
#include "../lib/std_lib_facilities.h"

class Point {
public:
    Point() = default;
    Point(double xx, double yy);
    double x{0};
    double y{0};
};

bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);
istream& operator>>(istream& ist, Point& p);
ostream& operator<<(ostream& ost, const Point& p);

#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_POINT_H

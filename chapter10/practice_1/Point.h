#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_POINT_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_POINT_H
#include "../lib/std_lib_facilities.h"
class Point{
public:
    Point()=default;
    Point(double xx, double yy);
    double x{0};
    double y{0};
};

istream& operator>>(istream& is, Point& p);
ostream& operator<<(ostream& os, const Point& p);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_POINT_H

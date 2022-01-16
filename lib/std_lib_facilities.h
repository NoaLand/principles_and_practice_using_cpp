#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_STD_LIB_FACILITIES_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_STD_LIB_FACILITIES_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<numeric>

using namespace std;

inline void keep_window_open() {
    char ch;
    cin >> ch;
}

inline void simple_error(const string& err) {
    throw runtime_error(err);
}

#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_STD_LIB_FACILITIES_H

#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_STD_LIB_FACILITIES_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_STD_LIB_FACILITIES_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<numeric>
#include<random>
#include <fstream>

using namespace std;

inline int keep_window_open(const string& input = "") {
    for(string ch; cin >> ch;)
        if(ch == input)
            return 1;
}

inline void simple_error(const string& err) {
    throw runtime_error(err);
}

#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_STD_LIB_FACILITIES_H

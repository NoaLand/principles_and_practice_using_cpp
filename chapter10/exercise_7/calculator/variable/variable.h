#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_VARIABLE_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_VARIABLE_H
#include"../../../../lib/std_lib_facilities.h"
class Variable {
public:
    string name;
    double value;
    bool is_const;
};

class Symbol_table {
public:
    double get_value(const string&);
    void set_value(const string&, double);
    bool is_declared(const string&);
    double define_name(const string&, double, bool=false);
private:
    vector<Variable> var_table;
};
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_VARIABLE_H

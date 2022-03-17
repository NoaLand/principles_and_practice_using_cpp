#include "variable.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
double Symbol_table::get_value(const string& s) {
    for(const Variable& v: var_table) {
        if(v.name == s) {
            return v.value;
        }
    }
    simple_error("get: undefined variable " + s);
}
#pragma clang diagnostic pop

void Symbol_table::set_value(const string& s, double d) {
    for(Variable& v: var_table) {
        if(v.name == s) {
            if(!v.is_const) {
                v.value = d;
                return;
            } else {
                simple_error("set: variable is const, cannot change");
            }
        }
    }
    simple_error("set: undefined variable " + s);
}

bool Symbol_table::is_declared(const string& var) {
    return std::any_of(
            var_table.begin(),
            var_table.end(),
            [var](const Variable& v){return v.name == var;}
    );
}

double Symbol_table::define_name(const string& var, double val, bool is_const) {
    if(is_declared(var)) simple_error(var + " declared twice");
    var_table.push_back({var, val, is_const});

    return val;
}

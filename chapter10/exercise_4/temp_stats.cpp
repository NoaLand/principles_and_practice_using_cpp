#include "../lib/std_lib_facilities.h"

enum class Temp_type {
    C, F
};

struct Reading {
    int hour{-1};
    double temperature{-999};
    Temp_type type;
};

istream& operator>>(istream& is, Reading& r) {
    int hour;
    double temperature;
    char temp_type;
    is >> hour >> temperature >> temp_type;
    if(!is) {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    if(hour < 0 || hour > 23) simple_error("wrong hour format: " + to_string(hour));

    switch (temp_type) {
        case 'c':
            r = {hour, temperature, Temp_type::C};
            break;
        case 'f':
            r = {hour, temperature, Temp_type::F};
            break;
        default:
            simple_error("wrong temp type: " + to_string(temp_type));
            break;
    }

    return is;
}

double calculate_average(const vector<Reading> &readings);

double calculate_median(vector<Reading> &readings);

void to_fahrenheit(Reading &reading);

int main() {
    cout << "please enter input raw data file: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) simple_error("wrong ist");

    vector<Reading> readings;
    for(Reading r; ist >> r;) {
        if(r.type == Temp_type::C) {
            to_fahrenheit(r);
        }
        readings.push_back(r);
    }

    double average = calculate_average(readings);
    cout << "average temp: " << average << endl;

    double median_value = calculate_median(readings);
    cout << "median value: " << median_value << endl;

    keep_window_open();
    return 0;
}

void to_fahrenheit(Reading &reading) {
    reading.temperature = reading.temperature * 1.8 + 32;
    reading.type = Temp_type::F;
}

double calculate_median(vector<Reading> &readings) {
    std::sort(readings.begin(), readings.end(),
              [](const Reading& a, const Reading& b) -> bool {
        return a.temperature > b.temperature;
    });

    double median_value;
    unsigned long size = readings.size();
    if(size % 2 == 0) {
        median_value = (readings[size / 2].temperature + readings[size / 2 - 1].temperature) / 2.0;
    } else {
        median_value = readings[size / 2].temperature;
    }

    return median_value;
}

double calculate_average(const vector<Reading> &readings) {
    double total_temp{0};
    for(Reading r : readings) {
        total_temp += r.temperature;
    }

    return total_temp / static_cast<double>(readings.size());
}

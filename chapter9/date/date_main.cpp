#include "Chrono.h"
#include "../lib/std_lib_facilities.h"

int main() {
    bool res1 = Chrono::leapyear(2000);
    cout << "2000 is leap year? " << res1 << endl;

    bool res2 = Chrono::leapyear(2100);
    cout << "2100 is leap year? " << res2 << endl;

    bool res3 = Chrono::leapyear(2004);
    cout << "2004 is leap year? " << res3 << endl;

    bool res4 = Chrono::leapyear(2005);
    cout << "2005 is leap year? " << res4 << endl;

    Chrono::Date my_day = Chrono::Date{2022, Chrono::Month::feb, 19};
    Chrono::Day weekday = Chrono::day_of_week(my_day);
    cout << "my day's weekday is: " << int(weekday) << endl;

    const Chrono::Date &next_workday = Chrono::next_workday(my_day);
    cout << "next workday is: " << next_workday << endl;

    int week_of_year = Chrono::week_of_year(my_day);
    cout << "week of year is: " << week_of_year << endl;

    keep_window_open();
    return 0;
}

#include <utility>

#include "../lib/std_lib_facilities.h"

class Person {
public:
    Person(string f, string l, string p, string e);
    string first_name;
    string last_name;
    string phone;
    string email;
};

ostream& operator<<(ostream& os, const Person& p);

Person::Person(string f, string l, string p, string e):
        first_name{std::move(f)}, last_name{std::move(l)}, phone{std::move(p)}, email{std::move(e)} {
}

ostream &operator<<(ostream &os, const Person& p) {
    return os << '|' << setw(15) << p.first_name
              << '|' << setw(15) << p.last_name
              << '|' << setw(20) << p.phone
              << '|' << setw(30) << p.email << '|';
}

int main() {
    Person p_temp{"first name", "last name", "phone", "email"};
    Person p1{"edward", "noaland", "12345678", "edwardnoaland@xxx.com"};
    Person p2{"p2", "noaland", "12345", "p2noaland@xxx.com"};
    Person p3{"p3", "noaland", "1234", "p3noaland@xxx.com"};
    Person p4{"p4xxx", "noa", "1237xx", "p4noaland@xxx.com"};
    Person p5{"p5xxxxxxxx", "noaland12", "1237xxxxxxxxx", "p5noaland@xxx.com"};

    vector<Person> p_list{p_temp, p1, p2, p3, p4, p5};

    for(const Person& p : p_list) {
        cout << p << endl;
    }

    keep_window_open();
    return 0;
}

#include<../lib/std_lib_facilities.h>

int main() {
    cout << "Please enter your first name and age:\n";
    string first_name = "???";
    double age = -1.0;
    cin >> first_name >> age;
    cout << "Hello, " << first_name << "(age " << age * 12 << " months)\n";

    return 0;
}

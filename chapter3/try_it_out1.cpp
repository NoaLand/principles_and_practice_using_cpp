#include<../lib/std_lib_facilities.h>

int main() {
    // try it out 1
//    cout << "Please enter your first name and age:\n";
//    string first_name = "???";
//    double age = -1.0;
//    cin >> first_name >> age;
//    cout << "Hello, " << first_name << "(age " << age * 12 << " months)\n";

    // try it out 2
    int number_of_words = 0;
    string previous = "";
    string current;
    while(cin >> current) {
        if(previous == current) {
            ++number_of_words;
            cout << "word number: " << number_of_words
                 << " repeated: " << current << endl;
        }

        previous = current;
    }

    return 0;
}

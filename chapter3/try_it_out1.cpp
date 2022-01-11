#include<../lib/std_lib_facilities.h>

void try_it_out_1();

void try_it_out_2();

void exercise_1();

int main() {
    // try_it_out_1();

    // try_it_out_2();

    exercise_1();

    return 0;
}

void exercise_1() {
    string first_name{"???"};
    int age{0};
    string friend_name{"???"};
    char gender{0};
    cout << "Enter the name of the person you want to write to and his or her age: \n";
    cin >> first_name >> age;
    if (age < 0 || age > 110)
        simple_error("you're kidding!");

    cout << "Enter your friend name and gender: \n";
    cin >> friend_name >> gender;

    cout << "Dear " << first_name << ", \n\n";
    cout << "\tHow are you? I am fine. I miss you.\n";
    cout << "\tHave you seen " << friend_name << " lately?";

    if (gender == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.";
    if (gender == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.";

    cout << "\n\tI hear you just had a birthday and you are " << age << " years old. ";

    if (age < 12)
        cout << "Next year you will be " << ++age << ". \n";
    if (age == 17)
        cout << "Next year you will be able to vote.\n";
    if (age > 70)
        cout << "I hope you are enjoying retirement.\n\n";

    cout << "Yours sincerely,\n";
    cout << "\n\n";
    cout << "Edward NoaLand";
}

void try_it_out_2() {
    int number_of_words = 0;
    string previous = "";
    string current;
    while (cin >> current) {
        if (previous == current) {
            ++number_of_words;
            cout << "word number: " << number_of_words
                 << " repeated: " << current << endl;
        }

        previous = current;
    }
}

void try_it_out_1() {
    cout << "Please enter your first name and age:\n";
    string first_name = "???";
    double age = -1.0;
    cin >> first_name >> age;
    cout << "Hello, " << first_name << "(age " << age * 12 << " months)\n";
}

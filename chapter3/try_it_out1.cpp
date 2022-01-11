#include<../lib/std_lib_facilities.h>

void try_it_out_1();

void try_it_out_2();

void exercise_1_email_template();

void exercise_2_convert_mi_to_km();

void exercise_3_output_res_of_two_int_val();

void exercise_4_sort_and_output_int();

int get_max(int i1, int i2, int i3);

int get_min(int i1, int i2, int i3);

void exercise_5_sort_and_output_string();

string get_max_string(const string &basicString, const string &basicString1, const string &basicString2);

string get_min_string(const string &s1, const string &s2, const string &s3);

void exercise_6_say_it_even_or_odd();

void exercise_7_convert_string_to_int();

int main() {
    // try_it_out_1();

    // try_it_out_2();

    // exercise_1_email_template();

    // exercise_2_convert_mi_to_km();

    // exercise_3_output_res_of_two_int_val();

    // exercise_4_sort_and_output_int();

    // exercise_5_sort_and_output_string();

    // exercise_6_say_it_even_or_odd();

    exercise_7_convert_string_to_int();

    keep_window_open();

    return 0;
}

void exercise_7_convert_string_to_int() {
    string string_num;
    cout << "Please input number in string:\n";
    cin >> string_num;

    if (string_num == "zero") {
        cout << "0\n";
    } else if (string_num == "one") {
        cout << "1\n";
    } else if (string_num == "two") {
        cout << "2\n";
    } else if (string_num == "three") {
        cout << "3\n";
    } else if (string_num == "four") {
        cout << "4\n";
    } else {
        cout << "stupid computer!\n";
    }
}

void exercise_6_say_it_even_or_odd() {
    int input{0};
    cout << "Please enter a number:\n";
    cin >> input;

    if (input % 2 == 0) {
        cout << "The value " << input << " is an even number.\n";
    } else {
        cout << "The value " << input << " is an odd number.\n";
    }
}

void exercise_5_sort_and_output_string() {
    string s1, s2, s3;
    string max, mid, min;
    cout << "Please enter 3 string:\n";
    cin >> s1 >> s2 >> s3;

    max = get_max_string(s1, s2, s3);
    min = get_min_string(s1, s2, s3);

    for (const string &s: {s1, s2, s3}) {
        if (s != max && s != min) {
            mid = s;
        }
    }

    cout << min << "," << mid << "," << max << endl;
}

string get_min_string(const string &s1, const string &s2, const string &s3) {
    string mid = s1 < s2 ? s1 : s2;
    string min = mid < s3 ? mid : s3;

    return min;
}

string get_max_string(const string &s1, const string &s2, const string &s3) {
    string mid = s1 > s2 ? s1 : s2;
    string max = mid > s3 ? mid : s3;

    return max;
}

void exercise_4_sort_and_output_int() {
    int i1{0}, i2{0}, i3{0};
    int max{0}, mid{0}, min{0};
    cout << "Please enter 3 int value:\n";
    cin >> i1 >> i2 >> i3;

    max = get_max(i1, i2, i3);
    min = get_min(i1, i2, i3);
    mid = i1 + i2 + i3 - max - min;

    cout << min << "," << mid << "," << max << endl;
}

int get_min(int i1, int i2, int i3) {
    int mid = i1 < i2 ? i1 : i2;
    int min = mid < i3 ? mid : i3;

    return min;
}

int get_max(int i1, int i2, int i3) {
    int mid = i1 > i2 ? i1 : i2;
    int max = mid > i3 ? mid : i3;

    return max;
}


void exercise_3_output_res_of_two_int_val() {
    int val1{0}, val2{0};

    cout << "Please enter two int value:\n";
    cin >> val1 >> val2;

    cout << "min val: " << (val1 < val2 ? val1 : val2) << endl;
    cout << "max val: " << (val1 > val2 ? val1 : val2) << endl;
    cout << "sum is: " << val1 + val2 << endl;
    cout << "diff is: " << val1 - val2 << endl;
    cout << "product is: " << val1 * val2 << endl;
    cout << "ratio is: " << (double) val1 / val2 << endl;
}

void exercise_2_convert_mi_to_km() {
    double mi{0.0}, km;
    cout << "Please enter the mi you want to convert:\n";
    cin >> mi;
    km = mi * 1.609;
    cout << mi << " mi is: " << km << " km";
}

void exercise_1_email_template() {
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

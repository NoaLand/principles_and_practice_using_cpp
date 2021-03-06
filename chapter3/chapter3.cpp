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

void exercise_8_custom_operation();

void exercise_9_banking_system();

int convert_pennies_to_cents(int pennies);

int convert_nickels_to_cents(int nickels);

int convert_dimes_to_cents(int dimes);

int convert_quarters_to_cents(int quarters);

int convert_half_dollars_to_cents(int dollars);

int convert_one_dollar_to_cents(int one_dollar);

string unit_grammar(int money, const string& unit);

int main() {
    // try_it_out_1();

    // try_it_out_2();

    // exercise_1_email_template();

    // exercise_2_convert_mi_to_km();

    // exercise_3_output_res_of_two_int_val();

    // exercise_4_sort_and_output_int();

    // exercise_5_sort_and_output_string();

    // exercise_6_say_it_even_or_odd();

    // exercise_7_convert_string_to_int();

    // exercise_8_custom_operation();

    exercise_9_banking_system();

    keep_window_open();

    return 0;
}

void exercise_9_banking_system() {
    int pennies, nickels, dimes, quarters, half_dollars, one_dollar;
    int total{0};

    cout << "How many pennies do you have?\n";
    cin >> pennies;
    cout << "How many nickels do you have?\n";
    cin >> nickels;
    cout << "How many dimes do you have?\n";
    cin >> dimes;
    cout << "How many quarters do you have?\n";
    cin >> quarters;
    cout << "How many half dollars do you have?\n";
    cin >> half_dollars;
    cout << "How many one dollar do you have?\n";
    cin >> one_dollar;

    total += convert_pennies_to_cents(pennies);
    total += convert_nickels_to_cents(nickels);
    total += convert_dimes_to_cents(dimes);
    total += convert_quarters_to_cents(quarters);
    total += convert_half_dollars_to_cents(half_dollars);
    total += convert_one_dollar_to_cents(one_dollar);

    cout << "You have " << pennies << " " << unit_grammar(pennies, "penny") << endl;
    cout << "You have " << nickels << " " << unit_grammar(nickels, "nickel") << endl;
    cout << "You have " << dimes << " " << unit_grammar(dimes, "dime") << endl;
    cout << "You have " << quarters << " " << unit_grammar(quarters, "quarter") << endl;
    cout << "You have " << half_dollars << " " << unit_grammar(half_dollars, "half dollar") << endl;
    cout << "You have " << one_dollar << " " << unit_grammar(one_dollar, "dollar") << endl;
    cout << "The value of all of your coins is $" << total / 100.0 << "." << endl;
}

string unit_grammar(int money, const string& unit) {
    map<string, string> unit_grammar_map = {
            {"penny", "pennies"},
            {"nickel", "nickels"},
            {"dime", "dimes"},
            {"quarter", "quarters"},
            {"half dollar", "half dollars"},
            {"dollar", "dollars"},
    };

    if(money == 1) {
        return unit;
    } else {
        return unit_grammar_map[unit];
    }
}

int convert_one_dollar_to_cents(int one_dollar) {
    return one_dollar * 100;
}

int convert_half_dollars_to_cents(int half_dollars) {
    return half_dollars * 50;
}

int convert_quarters_to_cents(int quarters) {
    return quarters * 25;
}

int convert_dimes_to_cents(int dimes) {
    return dimes * 10;
}

int convert_nickels_to_cents(int nickels) {
    return nickels * 5;
}

int convert_pennies_to_cents(int pennies) {
    return pennies * 1;
}

void exercise_8_custom_operation() {
    string operation;
    double input_1, input_2;
    cout << "Please enter operation:\n";
    cin >> operation >> input_1 >> input_2;

    if(operation == "+") {
        cout << "res: " << input_1 + input_2 << endl;
    }
    if(operation == "-") {
        cout << "res: " << input_1 - input_2 << endl;
    }
    if(operation == "*") {
        cout << "res: " << input_1 * input_2 << endl;
    }
    if(operation == "/") {
        cout << "res: " << input_1 / input_2 << endl;
    }
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

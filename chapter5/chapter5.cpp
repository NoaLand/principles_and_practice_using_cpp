#include <../lib/std_lib_facilities.h>

void try_it_out_1();

int area(int length, int width);

void try_it_out_2();

void exercise_1_to_25_get_used_with_compile_err();

void my_code();

void exercise_26_and_27_and_28_29_ctok_and_ktoc();

double ctok(double c);

double ktoc(double k);

void exercise_30_dc_to_df_and_df_to_dc();

double dc_to_df(double dc);

double df_to_dc(double df);

void exercise_31_solve_one_dimensional_quadratic_equation();

void exercise_32_get_sum_of_int_vector();

void exercise_33_get_sum_of_double_vector();

void exercise_34_fibonacci_number();

void exercise_35_bulls_and_cows_game_v1();

vector<int> generate_rand_nums();

[[noreturn]] void exercise_36_bulls_and_cows_game_v2();

int main() {
    // try_it_out_1();
    // try_it_out_2();
    // exercise_1_to_25_get_used_with_compile_err();
    // exercise_26_and_27_and_28_29_ctok_and_ktoc();
    // exercise_30_dc_to_df_and_df_to_dc();
    // exercise_31_solve_one_dimensional_quadratic_equation();
    // exercise_32_get_sum_of_it_vector();
    // exercise_33_get_sum_of_double_vector();
    // exercise_34_fibonacci_number();
    // exercise_35_bulls_and_cows_game_v1();
    exercise_36_bulls_and_cows_game_v2();

    keep_window_open();
    return 0;
}

[[noreturn]] void exercise_36_bulls_and_cows_game_v2() {
    while(true) {
        vector<int> expected_nums = generate_rand_nums();
        int correct_number{0}, correct_position{0};

        while(!(correct_number == correct_position && correct_number == expected_nums.size())) {
            // reinit number and position
            correct_number = 0;
            correct_position = 0;

            int a, b, c, d;
            vector<int> actual_nums;
            // get input
            cout << "Please enter nums you guess:\n";
            cin >> a >> b >> c >> d;
            actual_nums.push_back(a);
            actual_nums.push_back(b);
            actual_nums.push_back(c);
            actual_nums.push_back(d);

            // match numbers and positions
            for(int expected_index = 0; expected_index < expected_nums.size(); ++expected_index) {
                for(int actual_index = 0; actual_index < actual_nums.size(); ++actual_index) {
                    if(expected_nums.at(expected_index) == actual_nums.at(actual_index)) {
                        ++correct_number;

                        if(expected_index == actual_index) {
                            ++correct_position;
                        }
                    }
                }
            }

            // print
            cout << "************\n";
            cout << correct_position << " bulls, and " << correct_number - correct_position << " cows\n";
            cout << "************\n";
            cout << endl;
        }

        cout << "!!! YOU WIN !!!" << endl;
    }
}

void exercise_35_bulls_and_cows_game_v1() {
    vector<int> expected_nums = generate_rand_nums();
    int correct_number{0}, correct_position{0};

    while(!(correct_number == correct_position && correct_number == expected_nums.size())) {
        // reinit number and position
        correct_number = 0;
        correct_position = 0;

        int a, b, c, d;
        vector<int> actual_nums;
        // get input
        cout << "Please enter nums you guess:\n";
        cin >> a >> b >> c >> d;
        actual_nums.push_back(a);
        actual_nums.push_back(b);
        actual_nums.push_back(c);
        actual_nums.push_back(d);

        // match numbers and positions
        for(int expected_index = 0; expected_index < expected_nums.size(); ++expected_index) {
            for(int actual_index = 0; actual_index < actual_nums.size(); ++actual_index) {
                if(expected_nums.at(expected_index) == actual_nums.at(actual_index)) {
                    ++correct_number;

                    if(expected_index == actual_index) {
                        ++correct_position;
                    }
                }
            }
        }

        // print
        cout << "************\n";
        cout << correct_position << " bulls, and " << correct_number - correct_position << " cows\n";
        cout << "************\n";
        cout << endl;
    }

    cout << "!!! YOU WIN !!!" << endl;
}

vector<int> generate_rand_nums() {
    vector<int> res;
    res.reserve(4);
    // generate random number with time -- see README.md
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    for(int index = 0; index < 4; ++index) {
        bool not_repeated = true;
        int rand_num = dist(mt);
        for(int i = 0; i < index; ++i) {
            if (rand_num == res.at(i)) {
                not_repeated = false;
                --index;
            }
        }

        if(not_repeated) {
            res.push_back(rand_num);
        }
    }
    return res;
}

void exercise_34_fibonacci_number() {
    int first{1}, second{1};
    int next;

    cout << "1. " << first << endl;
    cout << "2. " << second << endl;
    int i{3};
    while(i < 50) {
        next = first + second;
        cout << i << ". " << next << endl;
        first = second;
        second = next;

        ++i;
    }

    // the answer of the max fibonacci number that an int can store is 1836311903, this is the number 46 of fibonacci.
}

void exercise_33_get_sum_of_double_vector() {
    int total_num;
    double sum{0};
    string nums_string, diffs_string;
    vector<double> num_list, diff_between_element;
    cout << "Please enter the number of values you want to sum:\n";
    cin >> total_num;
    if(total_num < 1) simple_error("get wrong number, it should be more than 0 at least.");

    cout << "Please enter some integers (press '|' to stop):\n";
    for(double num; cin >> num;) {
        num_list.push_back(num);
    }

    if(total_num > num_list.size()) simple_error("out of range!");
    for(int index = 0; index < total_num; ++index) {
        sum += num_list.at(index);

        if (index == total_num - 1) {
            nums_string.append(to_string(num_list.at(index)));
        } else {
            nums_string.append(to_string(num_list.at(index))).append(" ");
        }
    }

    // calculate diff between two element
    for(int index = 1; index < total_num; ++index) {
        double diff = num_list.at(index) - num_list.at(index - 1);
        diff_between_element.push_back(diff);
    }

    // format print diff info
    for(double diff: diff_between_element) {
        diffs_string.append(to_string(diff)).append(" ");
    }

    cout << "The sum of the first " << total_num << " numbers (" << nums_string << ") is " << sum << ".\n";
    cout << "The diff of the first " << total_num << " numbers (" << nums_string << ") is " << diffs_string << "\n";
}

void exercise_32_get_sum_of_int_vector() {
    int total_num;
    int sum{0};
    string nums;
    vector<int> num_list;
    cout << "Please enter the number of values you want to sum:\n";
    cin >> total_num;
    if(total_num < 1) simple_error("get wrong number, it should be more than 0 at least.");

    cout << "Please enter some integers (press '|' to stop):\n";
    for(int num; cin >> num;) {
        num_list.push_back(num);
    }

    if(total_num > num_list.size()) simple_error("out of range!");
    for(int index = 0; index < total_num; ++index) {
        sum += num_list.at(index);

        if (index == total_num - 1) {
            nums.append(to_string(num_list.at(index)));
        } else {
            nums.append(to_string(num_list.at(index))).append(" ");
        }
    }

    cout << "The sum of the first " << total_num << " numbers (" << nums << ") is "<< sum << ".\n";
}

void exercise_31_solve_one_dimensional_quadratic_equation() {
    double a, b, c;
    cout << "Please enter ax^2 + bx + c\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    // solve one dimensional quadratic equation
    double square_root = b * b - 4 * a * c;
    if(square_root < 0) simple_error("square root is less than zero");

    cout << "x1 is: " << (-b + square_root) / (2 * a) << endl;
    cout << "x2 is: " << (-b - square_root) / (2 * a) << endl;
}

void exercise_30_dc_to_df_and_df_to_dc() {
    double dc = 0;
    cin >> dc;
    double df = dc_to_df(dc);
    cout << "convert dc to df is: " << df << endl;
    double dc_convert_back = df_to_dc(df);
    cout << "convert df to dc back is: " << dc_convert_back << endl;
}

double df_to_dc(double df) {
    if(df < -523.67) simple_error("cannot be less than absolute zero");
    double dc = (df - 32) / (9.0 / 5);

    return dc;
}

double dc_to_df(double dc) {
    if(dc < -273.15) simple_error("cannot be less than absolute zero");
    double df = 9.0 / 5 * dc + 32;

    return df;
}

void exercise_26_and_27_and_28_29_ctok_and_ktoc() {
    double c = 0; // declare input variable
    cin >> c; // get input, and store into variable
    double k = ctok(c); // convert temperature to absolute temperature
    cout << "the absolute temperature is: " << k << '\n'; // print absolute temperature
    double celsius = ktoc(k);
    cout << "convert back to celsius is: " << celsius << '\n'; // print celsius
}

// convert absolute temperature to celsius
double ktoc(double k) {
    if(k < 0) simple_error("cannot be less than absolute zero");
    double c = k - 273.15;
    return c;
}

// convert celsius to absolute temperature
double ctok(double c) {
    if(c < -273.15) simple_error("less than temperature physical law");
    double k = c + 273.15;
    return k;

}

void exercise_1_to_25_get_used_with_compile_err() {
    try {
        // your code here
        my_code();
    } catch(exception& e) {
        cerr << "error: " << e.what() << endl;
    } catch(...) {
        cerr << "Oops: unknown exception!" << endl;
    }
}

void my_code() {
    // 1. Cout << "Success!\n";  -- "Cout" is wrong, it should be "cout"
    // cout << "Success!\n";

    // 2. cout << "Success!\n; -- Lost " symbol
    // cout << "Success!\n";

    // 3. cout << "Success" << !\n" -- Lost " symbol, and ; symbol
    // cout << "Success" << "!\n";

    // 4. cout << success << '\n' -- Lost "" symbol
    // cout << "Success" << '\n';

    // 5.
    // string res = 7;
    // vector<int> v(10);
    // v[5] = res;
    // cout << "Success!\n";
    // -- type of res is wrong
    // -----------------------
    // int res = 7;
    // vector<int> v(10);
    // v[5] = res;
    // cout << "Success!\n";

    // 6.
    // vector<int> v(10);
    // v(5) = 7;
    // if(v(5) != 7)
    // cout << "Success!\n";
    // -- vector index symbol is wrong for () to [], cannot print Success, since
    // -- v[5] is 7, so add ; symbol after if statement
    // -----------------------
    // vector<int> v(10);
    // v[5] = 7;
    // if(v[5] != 7)
    //     ; // NOLINT(bugprone-suspicious-semicolon)
    // cout << "Success!\n";

    // 7.
    // if(cond)
    //     cout << "Success!\n";
    // else
    //     cout << "Fail!\n";
    // -- no cond declare, should declare cond as true
    // -----------------------
    // bool cond = true;
// #pragma clang diagnostic push
// #pragma ide diagnostic ignored "ConstantConditionsOC"
    // if(cond)
    //     cout << "Success!\n";
    // else
    //     cout << "Fail!\n";
// #pragma clang diagnostic pop

    // 8.
    // bool c = false;
    // if(c) cout << "Success!\n";
    // else cout << "Fail!\n";
    // -- false will lead code to else statement
    // -----------------------
    // bool c = true;
    // if(c) cout << "Success!\n";
    // else cout << "Fail!\n";

    // 9.
    // string s = "ape";
    // boo c = "fool" < s;
    // if(c) cout << "Success!\n";
    // -- "fool" is bigger than "ape", and type boo does not exist
    // -----------------------
    // string s = "ape";
    // bool c = "fool" > s;
    // if(c) cout << "Success!\n";

    // 10.
    // string s = "ape";
    // if(s == "fool") cout << "Success!\n";
    // -- fool is not equal to s, change statement to not equal
    // -----------------------
    // string s = "ape";
    // if(s != "fool") cout << "Success!\n";

    // 11.
    // string s = "ape";
    // if(s == "fool") cout < "Success!\n";
    // -- the same as exercise 10, and "cout <" should be "cout <<"
    // -----------------------
    // string s = "ape";
    // if(s != "fool") cout << "Success!\n";

    // 12.
    // string s = "ape";
    // if(s + "fool") cout < "Success!\n";
    // -- s + "fool" is string, not a bool, and "cout <" should be "cout <<"
    // string s = "ape";
    // if(s + "fool" == "apefool") cout << "Success!\n";

    // 13.
    // vector<char> v(5);
    // for(int i = 0; i < v.size(); ++i);
    // cout << "Success\n";
    // -- no error

    // 14.
    // vector<char> v(5);
    // for(int i = 0; i <= v.size(); ++i);
    // cout << "Success!\n";
    // -- potential compile or logistic error, i <= v.size() may create out of range error

    // 15.
    // string s = "Success!\n";
    // for(int i = 0; i < 6; ++i)
    //     cout << s[i];
    // -- 6 will only print part of string s
    // -----------------------
    // string s = "Success!\n";
    // for(int i = 0; i < s.length(); ++i)
    //     cout << s[i];

    // 16.
    // if(true) then cout << "Success!\n";
    // else cout << "Fail!\n";
    // -- no keyword named then
    // -----------------------
    // if(true) cout << "Success!\n";
    // else cout << "Fail!\n";

    // 17.
    // int x = 2000;
    // char c = x;
    // if(c == 2000) cout << "Success!\n";
    // -- c cannot be the same as 2000
    // -----------------------
    // int x = 2000;
    // char c = x;
    // if(c != 2000) cout << "Success!\n";

    // 18.
    // string s = "Success!\n";
    // for(int i = 0; i < 10; ++i)
    //     cout << s[i];
    // -- can print, but may out of range, and print something strange
    // -----------------------
    // string s = "Success!\n";
    // for(int i = 0; i < s.length(); ++i)
    //     cout << s[i];

    // 19.
    // vector v(5);
    // for(int i = 0; i <= v.size(); ++i) ;
    // cout << "Success!\n";
    // -- should declare type of the vector, and for loop may create potential logistic error
    // -----------------------
    // vector<int> v(5);
    // for(int i = 0; i < v.size(); ++i) ;
    // cout << "Success!\n";

    // 20.
    // int i = 0;
    // int j = 9;
    // while(i < 10)
    //     ++j;
    // if(j < i)
    //     cout << "Success!\n";
    // -- while loop will never end
    // -----------------------
    // int i = 0;
    // int j = 9;
    // while(i < 10)
    //     ++i;
    // if(j < i)
    //     cout << "Success!\n";

    // 21.
    // int x = 2;
    // double d = 5 / (x - 2);
    // if(d == 2 * x + 0.5)
    //     cout << "Success!\n";
    // -- in d declare, 5 will divide 0
    // -----------------------
    // int x = 2;
    // double d = 5.0 / x + 2;
    // if(d == 2 * x + 0.5)
    //     cout << "Success!\n";

    // 22.
    // string<char> s = "Success!\n";
    // for(int i = 0; i <= 10; ++i)
    //     cout << s[i];
    // -- should be string only, and i <= 10 potential create out of range error
    // -----------------------
    // string s = "Success!\n";
    // for(int i = 0; i <= s.size(); ++i)
    //     cout << s[i];

    // 23.
    // int i = 0;
    // while(i < 10)
    //     ++j;
    // if(j < i)
    //     cout << "Success!\n";
    // -- no j has been declared, and while loop will never end
    // -----------------------
    // int i = 0;
    // int j = 9;
    // while(i < 10)
    //     ++i;
    // if(j < i)
    //     cout << "Success!\n";

    // 24.
    // int x = 4;
    // double d = 5 / (x - 2);
    // if(d = 2 * x + 0.5)
    //     cout << "Success!\n":
    // -- double d will be 2.0, and d = 2 * x + 0.5 is a declare not an assert statement
    // -----------------------
    // int x = 4;
    // double d = 5.0 / (x - 2);
    // if(d == 2 * 1 + 0.5)
    //     cout << "Success!\n";

    // 25.
    // cin << "Success!\n";
    // -- should be cout, instead of cin
    // -----------------------
    cout << "Success!\n";
}

void try_it_out_2() {
    // int x0 = arena(7); // function "arena(int)" not declared
    // int x1 = area(7);  // number of param is not matched
    // int x2 = area("seven", 2); // the type of first param is not matched
}

void try_it_out_1() {
    // int s1 = area(7;   // symbol ) lost
    // int s2 = area(7)   // symbol ; lost
    // Int s3 = area(7);  // Int is not a type
    // int s4 = area('7); // symbol ' lost
}

int area(int length, int width) {
    return length * width;
}

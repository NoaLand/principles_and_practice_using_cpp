#include <../lib/std_lib_facilities.h>

void try_it_out_1();

int area(int length, int width);

void try_it_out_2();

void exercise_1_to_25_get_used_with_compile_err();

void my_code();

void exercise_26_and_27_and_28_ctok();

double ctok(double c);

int main() {
    // try_it_out_1();
    // try_it_out_2();
    // exercise_1_to_25_get_used_with_compile_err();
    exercise_26_and_27_and_28_ctok();

    keep_window_open();
    return 0;
}

void exercise_26_and_27_and_28_ctok() {
    double c = 0; // declare input variable
    cin >> c; // get input, and store into variable
    double k = ctok(c); // convert temperature
    cout << k << '\n'; // print temperature
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

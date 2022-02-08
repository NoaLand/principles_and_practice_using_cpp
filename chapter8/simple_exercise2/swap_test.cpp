#include<../lib/std_lib_facilities.h>

void swap_v(int, int);
void swap_r(int&, int&);
void swap_cr(const int&, const int&);

int main() {
    // test swap x_for_v and y_for_v with swap_v
    int x_for_v{7};
    int y_for_v{9};
    swap_v(x_for_v, y_for_v);
    cout << "x_for_v: " << x_for_v << ", y_for_v: " << y_for_v << endl;
    // didn't swap successfully, since x and y are created copy when get into function swap_v, and cleared after function finished.

    // test swap x_for_r and y_for_r with swap_r
    int x_for_r{7};
    int y_for_r{9};
    swap_r(x_for_r, y_for_r);
    cout << "x_for_r: " << x_for_r << ", y_for_r: " << y_for_r << endl;
    // swap successfully

    // can run, but will do nothing affect the main function
    swap_v(7, 9);
    // cannot compile, since swap_r needs lvalue params, but 7 and 9 are rvalue
    // swap_r(7, 9);

    // test swap cx_for_v and cy_for_v with swap_v
    const int cx_for_v{7};
    const int cy_for_v{9};
    swap_v(7, 9);
    cout << "cx_for_v: " << cx_for_v << ", cy_for_v: " << cy_for_v << endl;
    // didn't swap successfully, since cx and cy are only copied when code get into swap_v function like test above

    // test swap cx_for_r and cy_for_r with swap_r
    const int cx_for_r{7};
    const int cy_for_r{9};
    // swap_r(cx_for_r, cy_for_r);
    // cannot compile, since cx and cy are const

    swap_v(7.7, 9.9);
    // can compile, 7.7 and 9.9 will narrow cast to int, but will not affect anything

    // swap_r(7.7, 9.9);
    // cannot compile, swap_r needs lvalue, but get rvalue

    // test swap x_for_v and y_for_v with swap_v
    double dx_for_v{7.7};
    double dy_for_v{9.9};
    swap_v(dx_for_v, dy_for_v);
    cout << "dx_for_v: " << dx_for_v << ", dy_for_v: " << dy_for_v << endl;
    // can compile, dx and dy will narrow cast to int, but will not affect anything

    // test swap x_for_r and y_for_r with swap_r
    double dx_for_r{7.7};
    double dy_for_r{9.9};
    // swap_r(dx_for_r, dy_for_r);
    // cannot compile, `no matching function call swap_r`


    keep_window_open();
    return 0;
}

void swap_v(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// cannot pass compile, since `a` and `b` are declared as const, which means that a, and b cannot be modified during the function
//void swap_cr(const int& a, const int& b) {
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
//}

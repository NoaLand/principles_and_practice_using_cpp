#include "Book/Book.h"

int main() {
    My_Library::Book b1;
    cin >> b1;

    cout << "*********** NEW BOOK ***********" << endl;
    cout << b1;
    cout << "********************************" << endl;

    b1.borrowing();
    cout << "********* BORROW BOOK **********" << endl;
    cout << b1;
    cout << "********************************" << endl;

    b1.returning();
    cout << "********** RETURN BOOK *********" << endl;
    cout << b1;
    cout << "********************************" << endl;

    My_Library::Book b2;
    cin >> b2;

    cout << "b1 == b2: " << (b1 == b2) << endl;
    cout << "b1 != b2: " << (b1 != b2) << endl;

    keep_window_open();
    return 0;
}

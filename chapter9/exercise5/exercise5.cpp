#include "Book/Book.h"

int main() {
    My_Library::Book b;
    cin >> b;

    cout << "*********** NEW BOOK ***********" << endl;
    cout << b;
    cout << "********************************" << endl;

    b.borrowing();
    cout << "********* BORROW BOOK **********" << endl;
    cout << b;
    cout << "********************************" << endl;

    b.returning();
    cout << "********** RETURN BOOK *********" << endl;
    cout << b;
    cout << "********************************" << endl;

    keep_window_open();
    return 0;
}

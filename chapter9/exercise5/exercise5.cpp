#include "Book/Book.h"

int main() {
    My_Library::Library lib;

    My_Library::Book b1{"100-20-10-x", "first book", "author 1", Chrono::Date{2001, Chrono::Month::jan, 1}, My_Library::Genre::fiction};
    My_Library::Book b2{"100-21-10-x", "second book", "author 2", Chrono::Date{2021, Chrono::Month::oct, 31}, My_Library::Genre::nonfiction};
    My_Library::Book b3{"201-2-11-b", "third book", "author 3", Chrono::Date{2022, Chrono::Month::dec, 3}, My_Library::Genre::periodical};
    lib.add_book(b1);
    lib.add_book(b2);
    lib.add_book(b3);

    My_Library::Patron p1{"p1", "0001", 10.0};
    My_Library::Patron p2{"p2", "0002", -10.0};
    My_Library::Patron p3{"p3", "0003", 20.0};
    lib.add_patron(p1);
    lib.add_patron(p2);
    lib.add_patron(p3);


    cout << "all arrears patron: ";
    for(const string& name : lib.get_all_arrears_patron()) {
        cout << name << " ";
    }
    cout << endl;

    cout << "--------- 1st time ---------" << endl;
    lib.borrowing(b1, p1);
    lib.print_transactions();
    cout << "book1 borrowed: " << b1.get_is_borrowed() << endl;
    cout << "book3 borrowed: " << b3.get_is_borrowed() << endl;

    cout << endl;
    cout << "--------- 2nd time ---------" << endl;
    lib.borrowing(b3, p3);
    lib.print_transactions();
    cout << "book1 borrowed: " << b1.get_is_borrowed() << endl;
    cout << "book3 borrowed: " << b3.get_is_borrowed() << endl;

    cout << endl;
    cout << "--------- 3rd time ---------" << endl;
    lib.returning(b3, p3);
    lib.print_transactions();
    cout << "book1 borrowed: " << b1.get_is_borrowed() << endl;
    cout << "book3 borrowed: " << b3.get_is_borrowed() << endl;

    cout << endl;
    cout << "--------- 4th time ---------" << endl;
    lib.returning(b1, p1);
    lib.print_transactions();
    cout << "book1 borrowed: " << b1.get_is_borrowed() << endl;
    cout << "book3 borrowed: " << b3.get_is_borrowed() << endl;

    cout << endl;
    cout << "--------- 5th time ---------" << endl;
    lib.borrowing(b3, p3);
    lib.print_transactions();
    cout << "book1 borrowed: " << b1.get_is_borrowed() << endl;
    cout << "book3 borrowed: " << b3.get_is_borrowed() << endl;

    cout << endl;
    cout << "--------- 6th time ---------" << endl;
    lib.returning(b3, p3);
    lib.print_transactions();
    cout << "book1 borrowed: " << b1.get_is_borrowed() << endl;
    cout << "book3 borrowed: " << b3.get_is_borrowed() << endl;

    // should not return book
    try{
        cout << endl;
        cout << "--------- 7th time ---------" << endl;
        lib.returning(b1, p1);
    } catch (exception& e) {
        cout << "error: " << e.what() << endl;
    }

    // should not borrow when p2 is arrears
    try{
        cout << endl;
        cout << "--------- 8th time ---------" << endl;
        lib.borrowing(b1, p2);
    } catch (exception& e) {
        cout << "error: " << e.what() << endl;
    }

    keep_window_open();
    return 0;
}

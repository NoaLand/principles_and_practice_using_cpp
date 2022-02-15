#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H
#include "../lib/std_lib_facilities.h"

class Book {
public:
    Book();
    class Invalid: exception {};
    string get_isbn() const { return isbn; }
    string get_book_name() const { return book_name; }
    string get_author() const { return author; }
    string get_copyright_date() const { return copyright_date; }
    bool get_is_borrowed() const { return is_borrowed; }

    void borrowing();
    void returning();

private:
    Book(string isbn, string book_name, string author, string copyright_date);

    string isbn;
    string book_name;
    string author;
    string copyright_date;
    bool is_borrowed{false};
};

istream& operator>>(istream& is, Book& b);
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H

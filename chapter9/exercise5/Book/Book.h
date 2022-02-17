#ifndef PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H
#define PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H
#include "../../../lib/std_lib_facilities.h"
#include "../Chrono/Chrono.h"

namespace My_Library {
    enum class Genre {
        fiction, nonfiction, periodical, biography, children
    };
    
    class Book {
    public:
        class Invalid: exception {};

        Book();
        Book(string i, string bn, string a, Chrono::Date cd);

        string get_isbn() const { return isbn; }
        string get_book_name() const { return book_name; }
        string get_author() const { return author; }
        Chrono::Date get_copyright_date() const { return copyright_date; }
        bool get_is_borrowed() const { return is_borrowed; }

        void borrowing();
        void returning();
    private:
        string isbn;
        string book_name;
        string author;
        Chrono::Date copyright_date;
        bool is_borrowed{false};
    };

    istream& operator>>(istream& is, Book& b);
    ostream& operator<<(ostream& os, const Book& b);

    bool operator==(const Book& a, const Book& b);
    bool operator!=(const Book& a, const Book& b);

    bool isbn_is_qualified(const string&);
}
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H

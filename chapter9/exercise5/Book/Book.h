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
        Book(string i, string bn, string a, Chrono::Date cd, Genre g);

        string get_isbn() const { return isbn; }
        string get_book_name() const { return book_name; }
        string get_author() const { return author; }
        Chrono::Date get_copyright_date() const { return copyright_date; }
        bool get_is_borrowed() const { return is_borrowed; }
        string genre_to_string() const;

        void borrowing();
        void returning();
    private:
        string isbn;
        string book_name;
        string author;
        Chrono::Date copyright_date;
        bool is_borrowed{false};
        Genre genre;
    };

    istream& operator>>(istream& is, Book& b);
    ostream& operator<<(ostream& os, const Book& b);

    bool operator==(const Book& a, const Book& b);
    bool operator!=(const Book& a, const Book& b);

    bool isbn_is_qualified(const string&);
    Genre get_genre_from_string(const string& g);

    class Patron {
    public:
        Patron(string n, string lcn, double lf);

        string get_name() const { return name; }
        string get_lib_car_no() const { return lib_card_no; }
        double get_late_fee() const { return late_fee; }

        void set_late_fee(const double& fee);
    private:
        string name;
        string lib_card_no;
        double late_fee;
    };

    bool is_arrears(const Patron& p);
}
#endif //PRINCIPLES_AND_PRACTICE_USING_CPP_BOOK_H

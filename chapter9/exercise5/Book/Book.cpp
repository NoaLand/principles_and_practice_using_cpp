#include "Book.h"

#include <utility>
#include <sstream>

namespace My_Library {
    Book::Book(string i, string bn, string a, string cd):
            isbn{std::move(i)},
            book_name{std::move(bn)},
            author{std::move(a)},
            copyright_date{std::move(cd)} {
        if(!isbn_is_qualified(isbn)) throw Invalid{};
    }

    Book::Book(): isbn{"0-0-0-0"}, book_name{"default book"}, author{"default author"}, copyright_date{"(2001,1,1)"} {
        if(!isbn_is_qualified(isbn)) throw Invalid{};
    }

    istream &operator>>(istream &is, Book &b) {
        string isbn;
        cout << "isbn: ";
        getline(is, isbn);
        if(!isbn_is_qualified(isbn)) throw Book::Invalid{};

        string book_name;
        cout << "book name(max size 255): ";
        getline(is, book_name);

        string author;
        cout << "author: ";
        getline(is, author);

        string copyright_date;
        cout << "copyright date: ";
        getline(is, copyright_date);

        b = Book{isbn, book_name, author, copyright_date};

        return is;
    }

    ostream& operator<<(ostream& os, const Book& b) {
        os << "*** NEW BOOK ***" << endl;
        os << "isbn: " << b.get_isbn() << endl;
        os << "name: " << b.get_book_name() << endl;
        os << "author: " << b.get_author() << endl;
        os << "copyright date: " << b.get_copyright_date() << endl;
        os << "****************" << endl;

        return os;
    }

    bool isbn_is_qualified(const string &isbn) {
        stringbuf buffer;
        buffer.str(isbn);
        istream is(&buffer);

        int n1, n2, n3;
        char l1, l2, l3, x4;
        is >> n1 >> l1 >> n2 >> l2 >> n3 >> l3 >> x4;

        if(l1 != '-' || l2 != '-' || l3 != '-' || (!isdigit(x4) && !isalpha(x4))){
            is.clear(std::ios_base::failbit);
            return false;
        }

        return true;
    }
}

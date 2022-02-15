#include "Book.h"

#include <utility>

Book::Book(string isbn, string book_name, string author, string copyright_date):
    isbn{std::move(isbn)},
    book_name{std::move(book_name)},
    author{std::move(author)},
    copyright_date{std::move(copyright_date)} {
}

Book::Book(): isbn{""}, book_name{""}, author{""}, copyright_date{""} {
}

istream &operator>>(istream &is, Book &b) {
    int n1, n2, n3;
    char l1, l2, l3, x4;
    cout << "isbn: ";
    is >> n1 >> l1 >> n2 >> l2 >> n3 >> l3 >> x4;

    if(!is) return is;
    if(l1 != '-' || l2 != '-' || l3 != '-' || (!isdigit(x4) && !isalpha(x4))){
        is.clear(std::ios_base::failbit);
        return is;
    }

    string isbn = to_string(n1) + l1 + to_string(n2) + l2 + to_string(n3) + l3 + to_string(x4);

    string book_name;
    cout << "book name: ";
    is >> book_name;

    string author;
    cout << "author: ";
    is >> author;

    string copyright_date;
    cout << "copyright date: ";
    is >> copyright_date;

    b = Book{isbn, book_name, author, copyright_date};

    return is;
}

#include "Book.h"

#include <utility>
#include <sstream>

namespace My_Library {
    Book::Book(string i, string bn, string a, Chrono::Date cd, Genre g):
            isbn{std::move(i)},
            book_name{std::move(bn)},
            author{std::move(a)},
            copyright_date{cd},
            genre{g} {
        if(!isbn_is_qualified(isbn)) throw Invalid{};
    }

    Book::Book(): isbn{"0-0-0-0"}, book_name{"default book"}, author{"default author"}, copyright_date{Chrono::default_date()}, genre{Genre::nonfiction} {
        if(!isbn_is_qualified(isbn)) throw Invalid{};
    }

    void Book::borrowing() {
        if(is_borrowed) {
            simple_error("cannot borrow book which has already been borrowed!");
        } else {
            is_borrowed = true;
        }
    }

    void Book::returning() {
        if(!is_borrowed) {
            simple_error("book is not borrowed!");
        } else {
            is_borrowed = false;
        }
    }

    string Book::genre_to_string() const {
        switch(genre) {
            case Genre::fiction:
                return "fiction";
            case Genre::nonfiction:
                return "nonfiction";
            case Genre::periodical:
                return "periodical";
            case Genre::biography:
                return "biography";
            case Genre::children:
                return "children";
        }
    }

    istream &operator>>(istream &is, Book &b) {
        if(!is) return is;

        string isbn;
        cout << "isbn: ";
        getline(is, isbn);

        // this is for continue get, while getline gets an empty string
        // situation: when you cin >> b1, then cin >> b2, b2 will get a blank line for isbn first
        while(isbn.length() == 0)
            getline(is, isbn);

        if(!isbn_is_qualified(isbn)) throw Book::Invalid{};

        string book_name;
        cout << "book name: ";
        getline(is, book_name);

        string author;
        cout << "author: ";
        getline(is, author);

        Chrono::Date copyright_date;
        cout << "copyright date(yyyy-mm-dd): ";
        is >> copyright_date;

        string genre_str;
        cout << "genre_str: ";
        is >> genre_str;
        Genre genre = get_genre_from_string(genre_str);

        b = Book{isbn, book_name, author, copyright_date, genre};

        return is;
    }

    ostream& operator<<(ostream& os, const Book& b) {
        os << "****************" << endl;
        os << "isbn: " << b.get_isbn() << endl;
        os << "name: " << b.get_book_name() << endl;
        os << "author: " << b.get_author() << endl;
        os << "genre: " << b.genre_to_string() << endl;
        os << "copyright date: " << b.get_copyright_date() << endl;
        os << "status: " << (b.get_is_borrowed() ? "borrowed" : "stock") << endl;
        os << "****************" << endl;

        return os;
    }

    bool operator==(const Book& a, const Book& b) {
        return a.get_isbn() == b.get_isbn();
    }

    bool operator!=(const Book& a, const Book& b) {
        return !(a == b);
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

    Genre get_genre_from_string(const string& g) {
        if(g == "fiction") {
            return Genre::fiction;
        } else if(g == "nonfiction") {
            return Genre::nonfiction;
        } else if(g == "periodical") {
            return Genre::periodical;
        } else if(g == "biography") {
            return Genre::biography;
        } else if(g == "children") {
            return Genre::children;
        } else {
            throw Book::Invalid{};
        }
    }

    bool is_arrears(const Patron &p) {
        return p.get_late_fee() < 0;
    }

    Patron::Patron(string n, string lcn, double lf): name{std::move(n)}, lib_card_no{std::move(lcn)}, late_fee{lf} {
    }

    void Patron::set_late_fee(const double &fee) {
        late_fee = fee;
    }

    void Patron::spend(const double& fee) {
        late_fee -= fee;
    }

    void Library::add_book(const Book& book) {
        for(const Book& b : book_list) {
            if(b == book) simple_error("duplicated book");
        }

        book_list.push_back(book);
    }

    void Library::add_patron(const Patron &patron) {
        for(const Patron& p : patron_list) {
            if(p.get_lib_car_no() == patron.get_lib_car_no()) simple_error("duplicated patron");
        }

        patron_list.push_back(patron);
    }

    void Library::add_transaction(const Transaction &transaction) {
        for(const Transaction& t : transaction_list) {
            if(t.b == transaction.b && t.p.get_lib_car_no() == transaction.p.get_lib_car_no()) simple_error("duplicated transaction");
        }

        transaction_list.push_back(transaction);
    }

    vector<string> Library::get_all_arrears_patron() const {
        vector<string> name_list;

        for(const Patron& p : patron_list) {
            if(p.get_late_fee() < 0) {
                name_list.push_back(p.get_name());
            }
        }

        return name_list;
    }
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Book class with all the required data members
class Book
{
public:
    int bookId;
    string author;
    string title;
    string subject;
    string publicationDate;
    int rackNum;
    bool isAvailable;

    Book(int id, string &title, string &author, string &subject, string &pubDate, int &rackNum, bool isAvailable)
    {
        this->bookId = id;
        this->title = title;
        this->author = author;
        this->subject = subject;
        this->publicationDate = pubDate;
        this->isAvailable = isAvailable;
    }
    bool isBookAvailable(int id)
    {
        return this->isAvailable;
    }
};

// Bookmanagement class to perform all the operations
class BookManagement
{
    unordered_map<int, Book *> books;

public:
    void addBook(int id, string &title, string &author, string &subject, string &pubDate, int &rackNum, bool isAvailable)
    {
        if (books.find(id) == books.end())
        {
            Book *book = new Book(id, title, author, subject, pubDate, rackNum, isAvailable);
            books[id] = book;
            cout << "Book is added." << endl;
        }
        else
        {
            cout << "Book with the given id already exists." << endl;
        }
    }

    void removeBook(int id)
    {
        auto it = books.find(id);
        if (it != books.end())
        {
            delete it->second;
            books.erase(it);
            cout << "Book is removed." << endl;
        }
        else
        {
            cout << "Book does not exist." << endl;
        }
    }
    Book *getBookById(int id)
    {
        auto it = books.find(id);
        if (it != books.end())
        {
            return it->second;
        }
        else
        {
            return NULL;
        }
    }
    // book by author name
    // book by subject
    // book by title
};

// class User for having members and librarians
class User
{
private:
    string userName;
    int age;

public:
    User(string &name, int &age)
    {
        this->userName = name;
        this->age = age;
    }
    string getName()
    {
        return this->userName;
    }
    int getAge()
    {
        return this->age;
    }
};

// Member class for defining the members in the library
class Member : public User
{
private:
    int memId;
    string email;
    int totalBooksIssued;

public:
    Member(string &name, int &age, int id, string &email, int &booksIssued) : User(name, age)
    {
        this->memId = id;
        this->email = email;
        this->totalBooksIssued = booksIssued;
    }
    int getMemberId()
    {
        return this->memId;
    }
    string getMemberEmail()
    {
        return this->email;
    }
    int getBooksIssued()
    {
        return this->totalBooksIssued;
    }
};

// Librarian class for defining the librarians
class Librarian : public User
{
private:
    int libId;

public:
    Librarian(string &name, int &age, int id) : User(name, age)
    {
        this->libId = id;
    }
    int getLibId()
    {
        return this->libId;
    }
    void setLibId(int id)
    {
        this->libId = id;
    }
};

// Bridge class for
class Bridge
{
private:
    BookManagement *bookManagement;
    UserManagement *UserManagement;

public:
    Bridge(BookManagement *bookManagement) : bookManagement(bookManagement) {}

    Book *findBookById(int id)
    {
        return bookManagement->getBookById(id);
    }
};

class UserManagement
{
private:
    unordered_map<int, Librarian *> librarians;
    unordered_map<int, Member *> members;
    unordered_map<int, vector<int>> issuedBooks;

public:
    Bridge *bridge;
    UserManagement(Bridge *bridge) : bridge(bridge) {}

    void addLibrarian(string &name, int &age, int &id)
    {
        if (librarians.find(id) == librarians.end())
        {
            Librarian *librarian = new Librarian(name, age, id);
            librarians[id] = librarian;
            cout << "Librarian added." << endl;
        }
        else
        {
            cout << "Librarian with the given id already exists." << endl;
        }
    }

    void removeLibrarian(int id)
    {
        auto it = librarians.find(id);
        if (it != librarians.end())
        {
            delete it->second;
            librarians.erase(it);
            cout << "User removed successfully." << endl;
        }
        else
        {
            cout << "User not found." << endl;
        }
    }

    void addMember(string &name, int &age, int &id, string &email, int &booksIssued)
    {
        if (members.find(id) == members.end())
        {
            Member *member = new Member(name, age, id, email, booksIssued);
            members[id] = member;
            cout << "Member added." << endl;
        }
        else
        {
            cout << "Member with the given id already exists." << endl;
        }
    }

    void removeMember(int id)
    {
        auto it = members.find(id);
        if (it != members.end())
        {
            delete it->second;
            members.erase(it);
            cout << "User removed successfully." << endl;
        }
        else
        {
            cout << "User not found." << endl;
        }
    }

    Librarian *findLibrarian(int id)
    {
        auto it = librarians.find(id);
        if (it == librarians.end())
        {
            return NULL;
        }
        else
        {
            return it->second;
        }
    }

    Member *findMember(int id)
    {
        auto it = members.find(id);
        if (it == members.end())
        {
            return NULL;
        }
        else
        {
            return it->second;
        }
    }

    void issueBook(Member *member, int bookId)
    {
        if (member != NULL && issuedBooks[member->getMemberId()].size() < 5)
        {
            issuedBooks[member->getMemberId()].push_back(bookId);
            cout << "Book issued to " << member->getName() << endl;
        }
        else
        {
            cout << "User cannot issue more books or user does not exist." << endl;
        }
    }

    void returnBook(Member *member, int bookId)
    {
        if (issuedBooks.find(member->getMemberId()) != issuedBooks.end())
        {
            auto memberBooks = issuedBooks[member->getMemberId()];
            bool found = false;
            for (auto memberBook = memberBooks.begin(); memberBook != memberBooks.end(); memberBook++)
            {
                if (*memberBook == bookId)
                {
                    memberBooks.erase(memberBook);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "User has not issued book with ID " << bookId << endl;
            }
        }
        else
        {
            cout << "User does not exist or has not issued any books." << endl;
        }
    }
};

class LibraryManagementSystem
{
private:
    BookManagement bookManagement;
    Bridge bridge;
    UserManagement userManagement;

public:
    LibraryManagementSystem() : bridge(&bookManagement), userManagement(&bridge) {}

    void addBook(int id, string &title, string &author, string &subject, string &publishDate, int &rackNum, bool available)
    {
        bookManagement.addBook(id, title, author, subject, publishDate, rackNum, available);
    }

    void removeBook(int id)
    {
        bookManagement.removeBook(id);
    }

    Book *getBookById(int id)
    {
        return bookManagement.getBookById(id);
    }

    void addMember(string &name, int age, int id, string email, int &booksIssued)
    {
        userManagement.addMember(name, age, id, email, booksIssued);
    }

    void removeMember(int id)
    {
        userManagement.removeMember(id);
    }

    void addLibrarian(string &name, int age, int id, string email, int &booksIssued)
    {
        userManagement.addLibrarian(name, age, id);
    }

    void removeLibrarian(int id)
    {
        userManagement.removeMember(id);
    }
    Member *findMember(int id)
    {
        return userManagement.findMember(id);
    }
    Librarian *findLibrarian(int id)
    {
        return userManagement.findLibrarian(id);
    }
};

int main()
{
    return 0;
}
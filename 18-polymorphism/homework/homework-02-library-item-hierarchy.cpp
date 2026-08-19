#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Polymorphism in a Backend Application

    Scenario:
    You are developing a backend application for a library management system. 
    The application needs to handle various types of items in the library, such as books, e-books, and audio CDs. 
    Each of these items has specific properties and actions associated with them.

    Requirements:

    1. Create a base class called LibraryItem with the following properties and methods:
        Properties:
        title (string): The title of the library item.
        year (int): The year of publication.
        Methods:
        virtual void checkout(): A virtual function that marks the item as checked out.
        virtual void checkin(): A virtual function that marks the item as checked in.
        virtual void displayInfo(): A virtual function that displays information about the item, 
        including its title and year of publication.

    2. Create three derived classes: Book, EBook, and AudioCD, each inheriting from LibraryItem. 
       These classes should have their own specific properties and methods:
        Book:
        Properties:
        author (string): The author of the book.
        Methods:
        Override the displayInfo() method to include information about the author.
        EBook:
        Properties:
        format (string): The format of the e-book (e.g., PDF, EPUB).
        Methods:
        Override the displayInfo() method to include information about the format.
        AudioCD:
        Properties:
        artist (string): The artist of the audio CD.
        Methods:
        Override the displayInfo() method to include information about the artist.

    3. In the main() function, create instances of Book, EBook, and AudioCD objects, each representing a library item.
    4. Create an array of pointers to LibraryItem objects and store the addresses of the items in the array.
    5. Use a loop to iterate through the array and perform the following actions:
        Check out and check in each item to simulate library operations.
        Display information about each item using the displayInfo() method.
    

    Example Output:

    Book Title: "The Great Gatsby"
    Author: F. Scott Fitzgerald
    Year: 1925
    Status: Checked out

    EBook Title: "The Hitchhiker's Guide to the Galaxy"
    Format: EPUB
    Year: 1979
    Status: Checked in

    Audio CD Title: "Abbey Road"
    Artist: The Beatles
    Year: 1969
    Status: Checked out

*/

// Solution
class LibraryItem {
    public:
        string title;
        int year;
        bool checkedOut;

        LibraryItem(const string& itemTitle, int itemYear) : title(itemTitle), year(itemYear), checkedOut(false) {}

        virtual void checkout() {
            checkedOut = true;
        }

        virtual void checkin() {
            checkedOut = false;
        }

        virtual void displayInfo() {
            cout << "Title: " << title << endl;
            cout << "Year: " << year << endl;
            cout << "Status: " << (checkedOut ? "Checked out" : "Checked in") << endl;
        }
};

// Derived class 1: Book
class Book : public LibraryItem {
    public:
        string author;

        Book(const string& bookTitle, const string& bookAuthor, int bookYear) : 
        LibraryItem(bookTitle, bookYear), author(bookAuthor) {}

        void displayInfo() override {
            LibraryItem::displayInfo();
            cout << "Author: " << author << endl;
        }
};

// Derived class 2: EBook
class EBook : public LibraryItem {
    public:
        string format;

        EBook(const string& ebookTitle, const string& ebookFormat, int ebookYear) : LibraryItem(ebookTitle, ebookYear), format(ebookFormat) {}

        void displayInfo() override {
            LibraryItem::displayInfo();
            cout << "Format: " << format << endl;
        }
};

// Derived class 3: AudioCD
class AudioCD : public LibraryItem {
    public:
        string artist;

        AudioCD(const string& cdTitle, const string& cdArtist, int cdYear) : LibraryItem(cdTitle, cdYear), artist(cdArtist) {}

        void displayInfo() override {
            LibraryItem::displayInfo();
            cout << "Artist: " << artist << endl;
        }
};


int main() {

    /*      Example usage:     */ 

    Book book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    EBook ebook("The Hitchhiker's Guide to the Galaxy", "EPUB", 1979);
    AudioCD cd("Abbey Road", "The Beatles", 1969);

    LibraryItem* items[] = {&book, &ebook, &cd};

    for (int i = 0; i < 3; i++) {
        items[i]->checkout();    // Simulate checking out the item
        items[i]->displayInfo(); // Display item information
        items[i]->checkin();     // Simulate checking in the item
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Create a library management program with C++ that models different types of items 
    (books and DVDs) and their late fee calculations. 
    Implement the missing parts of the code and complete the tasks below.

    Tasks:

    1. Implement the missing parts of the code, including the calculateLateFee method for both the Book and DVD classes.
    2. Initialize and update the totalItems static member in the LibraryItem class when a new item is created.
    3. In the main function, create instances of both Book and DVD, display their information, and calculate late fees for them.
    4. Finally, display the total number of library items using the totalItems static member.
*/

class LibraryItem {
    public:
        LibraryItem(const string& title) : title(title) {
            // Increment the totalItems count for each library item added.
            totalItems++;
        }

        virtual double calculateLateFee(int daysLate) const {}

        virtual void displayInfo() const {
            cout << "Title: " << title << endl;
        }

        // Add a static member to keep track of the total library items
        static int totalItems;

    protected:
        string title;
};

// Define the static member totalItems for the LibraryItem class here
// Initialize it to 0.
int LibraryItem::totalItems = 0;


class Book : public LibraryItem {
    public:
        Book(const string& title, const string& author) : LibraryItem(title), author(author) {
            // Increment the totalItems count for each book added.
            // Hint: Use the static member of the LibraryItem class.
            totalItems++;
        }

        double calculateLateFee(int daysLate) const override {
            // Implement the late fee calculation for books.
            return daysLate * 0.1; // Example late fee calculation for books (0.1 dollar per day)
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Author: " << author << std::endl;
        }

    private:
        string author;
};


class DVD : public LibraryItem {
    public:
        DVD(const string& title, int duration) : LibraryItem(title), duration(duration) {
            // Increment the totalItems count for each DVD added.
            // Hint: Use the static member of the LibraryItem class.
            totalItems++;
        }

        double calculateLateFee(int daysLate) const override {
            // Implement the late fee calculation for DVDs.
            return daysLate * 0.2; // Example late fee calculation for DVDs (0.2 dollar per day)
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Duration: " << duration << " minutes" << endl;
        }

    private:
        int duration;
};



int main() {
    
    // Create instances of Book and DVD and test their functionality.
    Book book("The Catcher in the Rye", "J.D. Salinger");
    DVD dvd("Inception", 148);

    // Display information and calculate late fees.
    cout << "Book Information:" << endl;
    book.displayInfo();
    cout << "Late Fee for the Book: $" << book.calculateLateFee(3) << endl;

    cout << "\nDVD Information:" << endl;
    dvd.displayInfo();
    cout << "Late Fee for the DVD: $" << dvd.calculateLateFee(2) << endl;

    // Display the total number of library items using the static member totalItems.
    cout << "\nTotal Library Items: " << LibraryItem::totalItems << endl;

    return 0;
}
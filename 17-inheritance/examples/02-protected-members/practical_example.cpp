#include <iostream>
#include <functional>
#include <string>

using namespace std;

hash<string> stringHash;


class User {
    public:
        User(const string& name, const string& email, const string& password)
            : name(name), email(email), _password(password) {}

        // Public method to access the protected member
        void displayToken() {
            cout << "Token: " << stringHash(_password) << endl;
        }

    protected:
        string _password;  // Protected member
        string name;
        string email;
};


class Customer : public User {
    public:
        Customer(const string& name, const string& email, const string& password, const string& customerId)
            : User(name, email, password), customer_id(customerId) {}

        // Additional methods specific to Customer
        void displayCustomerInfo() {
            cout << "Customer ID: " << customer_id << endl;
            cout << "Name: " << name << ", Email: " << email << endl;
            displayToken();  // Accessing token from the base class
        }

    private:
        string customer_id;
};


class Seller : public User {
    public:
        Seller(const string& name, const string& email, const string& password, const string& sellerId)
            : User(name, email, password), seller_id(sellerId) {}

        // Additional methods specific to Seller
        void displaySellerInfo() {
            cout << "Seller ID: " << seller_id << endl;
            cout << "Name: " << name << ", Email: " << email << endl;
            displayToken();  // Accessing token from the base class
        }

    private:
        string seller_id;
};


int main() {

    system("clear");

    Customer customer("John Doe", "john@example.com", "pass123", "C001");
    Seller seller("Jane Seller", "jane@example.com", "sellerpass", "S001");

    // Accessing protected member through public methods
    customer.displayCustomerInfo();
    seller.displaySellerInfo();

    return 0;
}

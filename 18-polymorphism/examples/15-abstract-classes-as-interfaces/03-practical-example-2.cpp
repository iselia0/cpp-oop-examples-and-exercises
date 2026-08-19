#include <iostream>
#include <string>

using namespace std;


// Interface representing a product
class IProduct {
    public:
        virtual int getOrderId() const = 0;
        virtual void deliveryAddress() const = 0;
};


// Abstract class representing a generic product
class Product {
    public:
        Product(const string& name, double price) : name(name), price(price) {}

        // A pure virtual method to get the product's description
        virtual string getDescription() const = 0;

        // Common method to display product information
        void displayInfo() const {
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
            cout << "Description: " << getDescription() << endl;
        }

    protected:
        string name;
        double price;
};


// Derived class for Electronics
class Electronics : public Product, public IProduct {
    public:
        Electronics(const string& name, double price, const string& brand, int orderId, const string &p_address)
            : Product(name, price), brand(brand), id(orderId), address(p_address) {}

        string getDescription() const override {
            return "Electronic product from " + brand;
        }

        int getOrderId() const override {
            return id;
        }

        void deliveryAddress() const override {
            cout << name << " address: " << address << endl;
        }

    private:
        int id;
        string brand;
        string address;
};


// Derived class for Clothing
class Clothing : public Product, public IProduct {
    public:
        Clothing(const string& name, double price, const string& size, int orderId, const string &p_address)
            : Product(name, price), size(size), id(orderId), address(p_address) {}

        string getDescription() const override {
            return "Clothing item in size " + size;
        }

        int getOrderId() const override {
            return id;
        }

        void deliveryAddress() const override {
            cout << name << " address: " << address << endl;
        }

    private:
        int id;
        string size;
        string address;
};


int main() {

    system("clear");

    Electronics laptop("Laptop", 999.99, "Dell", 14, "New Castle, United States");
    Clothing shirt("T-Shirt", 19.99, "Large", 12, "Delaware, United States");

    laptop.displayInfo();
    cout << "------" << endl;
    shirt.displayInfo();

    cout << "------" << endl;

    cout << "Laptop order id: " << laptop.getOrderId() << endl;
    cout << "Shirt order id:  " << shirt.getOrderId() << endl;

    cout << "------" << endl;

    laptop.deliveryAddress();
    shirt.deliveryAddress();
    
}

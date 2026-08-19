#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    Exercise: E-Commerce System Design

    Instructions:

    1. Define Product Management Interface:
        Create an interface named ProductManager with a virtual function displayProductDetails that takes an int productId as a parameter.
    2. Implement Abstract Cart Class:
        Create an abstract class named AbstractCart that extends the ProductManager interface.
        Provide common functionality for managing a shopping cart, including adding to the cart, 
        removing from the cart, displaying the cart, and an abstract method checkout.
    3. Implement Concrete Online Store Class:
        Create a concrete class named OnlineStore that implements both the ProductManager interface and extends the AbstractCart abstract class.
        Implement the displayProductDetails method for an online store-specific product details display.
        Implement the checkout method for online store-specific checkout logic.
    4. Implement Concrete Mobile App Class:
        Create a concrete class named MobileApp that implements both the ProductManager interface and extends the AbstractCart abstract class.
        Implement the displayProductDetails method for a mobile app-specific product details display.
        Implement the checkout method for mobile app-specific checkout logic.

    Tips:
        Tip 1: Think about the functionalities that are common to both the online store and mobile app, and those that are specific to each.
        Tip 2: Ensure that the abstract class provides a common structure for shopping cart management.
        Tip 3: Implement the virtual functions in the derived classes with specific details related to the online store and mobile app.
        Tip 4: Use virtual destructors in the interface and abstract class for proper cleanup.
        Tip 5: Test your implementations by creating instances of the classes and 
        performing operations like displaying product details, adding/removing items from the cart, and checking out.
*/

// Step 1: Define ProductManager interface
class ProductManager {
public:
    virtual void displayProductDetails(int productId) = 0;
    virtual ~ProductManager() = default; // Virtual destructor for proper cleanup
};

// Step 2: Define AbstractCart abstract class
class AbstractCart : public ProductManager {
protected:
    vector<int> cart;
    unordered_map<int, string> productCatalog;

public:
    AbstractCart() {
        // Populate the product catalog with some sample data
        productCatalog[101] = "Laptop";
        productCatalog[102] = "Smartphone";
        productCatalog[201] = "Tablet";
        productCatalog[202] = "Smartwatch";
    }

    void addToCart(int productId) {
        cart.push_back(productId);
        cout << "Product with ID " << productId << " added to cart." << endl;
    }

    void removeFromCart(int productId) {
        auto it = find(cart.begin(), cart.end(), productId);
        if (it != cart.end()) {
            cart.erase(it);
            cout << "Product with ID " << productId << " removed from cart." << endl;
        } else {
            cout << "Product with ID " << productId << " not found in cart." << endl;
        }
    }

    void displayCart() const {
        cout << "Cart contents:" << endl;
        for (int productId : cart) {
            cout << " - " << productCatalog.at(productId) << " (ID: " << productId << ")" << endl;
        }
    }

    virtual void checkout() = 0; // Pure virtual function for checkout
};

// Step 3: Implement OnlineStore class
class OnlineStore : public AbstractCart {
public:
    void displayProductDetails(int productId) override {
        cout << "Online Store Product Details for ID " << productId << ": " << productCatalog[productId] << endl;
    }

    void checkout() override {
        cout << "Online Store Checkout: Processing payment online." << endl;
        cart.clear(); // Clear the cart after checkout
    }
};

// Step 4: Implement MobileApp class
class MobileApp : public AbstractCart {
public:
    void displayProductDetails(int productId) override {
        cout << "Mobile App Product Details for ID " << productId << ": " << productCatalog[productId] << endl;
    }

    void checkout() override {
        cout << "Mobile App Checkout: Processing payment via mobile app." << endl;
        cart.clear(); // Clear the cart after checkout
    }
};

int main() {
    // Demonstrate the use of both the interface and abstract class

    OnlineStore onlineStore;
    onlineStore.displayProductDetails(101);
    onlineStore.addToCart(101);
    onlineStore.addToCart(102);
    onlineStore.displayCart();
    onlineStore.checkout();

    MobileApp mobileApp;
    mobileApp.displayProductDetails(201);
    mobileApp.addToCart(201);
    mobileApp.removeFromCart(202);
    mobileApp.displayCart();
    mobileApp.checkout();

    return 0;
}

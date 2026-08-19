#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    14. Pure virtual functions and Abstract classes
*/


/*
    Problem Statement:
    You are tasked with designing a system that can process payments using different payment methods in a web backend. 
    Create a C++ program that demonstrates the use of an abstract class to model different types of payment providers.

    Requirements:

    1. Create an abstract class PaymentMethod with the following features:
    Payment Processing Method: Include a method processPayment with a double parameter representing the amount to be processed.

    2. Implement two concrete subclasses of PaymentMethod:
    CreditCardPayment: Implement the processPayment function to display a message indicating that the payment is being processed using a credit card.
    PayPalPayment: Implement the processPayment function to display a message indicating that the payment is being processed using PayPal.

    3. Extend the PaymentMethod abstract class by adding the following common functionality:
    Payment Attempt Logging: Implement a method logPaymentAttempt that takes a double parameter representing the payment amount and displays a message indicating that a payment attempt for the given amount has been logged.

    4. In the main function, create instances of both CreditCardPayment and PayPalPayment. 
    Use these instances to demonstrate:
    Logging payment attempts for different amounts.
    Processing payments using each payment method.

    Note:
    Consider which methods should be pure virtual functions based on the commonality and variability among payment methods.
    Think about the common functionality that can be shared among different payment methods.
*/


int sum(int, int);


// Abstract class representing a payment method
class PaymentMethod {
    public:
        // Pure virtual function to process a payment
        virtual void processPayment(double amount) const = 0;

        // Common functionality shared among payment methods
        void logPaymentAttempt(double amount) const {
            cout << "Payment attempt for amount $" << amount << " logged." << endl;
        }
};

// Concrete subclass for processing credit card payments
class CreditCardPayment : public PaymentMethod {
    public:
        // Implementation of the pure virtual function
        void processPayment(double amount) const override {
            // Payment processing logic for credit card
            cout << "Processing credit card payment for amount $" << amount << "." << endl;
            // Additional logic specific to credit card payments
        }
};

// Concrete subclass for processing PayPal payments
class PayPalPayment : public PaymentMethod {
    public:
        // Implementation of the pure virtual function
        void processPayment(double amount) const override {
            // Payment processing logic for PayPal
            cout << "Processing PayPal payment for amount $" << amount << "." << endl;
            // Additional logic specific to PayPal payments
        }
};

int main() {

    // Create instances of concrete subclasses
    CreditCardPayment creditCardPayment;
    PayPalPayment payPalPayment;

    // Call common functionality from the abstract class
    creditCardPayment.logPaymentAttempt(50.0);
    payPalPayment.logPaymentAttempt(30.0);

    // Call specific functionality based on the type of payment method
    creditCardPayment.processPayment(50.0);
    payPalPayment.processPayment(30.0);

    return 0;
}

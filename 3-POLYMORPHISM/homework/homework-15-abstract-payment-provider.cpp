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



// Abstract class representing a payment method
class PaymentMethod {
    public:
        // TODO: Add a pure virtual function to process payment

        // TODO: Add a common function to log payment attempts
};

// Concrete subclass for processing credit card payments
class CreditCardPayment : public PaymentMethod {
    public:
        // TODO: Implement the processPayment function
};

// Concrete subclass for processing PayPal payments
class PayPalPayment : public PaymentMethod {
    public:
        // TODO: Implement the processPayment function
};


int main() {

    // TODO: Create instances of CreditCardPayment and PayPalPayment

    // TODO: Log payment attempts for different amounts

    // TODO: Process payments using each payment method

    return 0;
}

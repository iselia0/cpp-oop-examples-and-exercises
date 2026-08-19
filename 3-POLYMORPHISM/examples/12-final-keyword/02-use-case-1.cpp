#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    12. Final

    --- Final Virtual Functions ---
*/


/*
    In a web backend application written in C++, 
    you can also find practical use cases for final virtual functions. 

    Here's an example related to handling HTTP request routing and authentication:
*/

class RequestHandler {
    public:
        virtual bool Authenticate(const string& username, const string& password) final {
            // Common authentication logic here
            if (username == "admin" && password == "password123") {
                return true;
            }
            
            return false;
        }

        virtual void HandleRequest(const string& endpoint) = 0;
        /*
            '= 0' This is what makes the function a pure virtual function. 

            When a function is declared as pure virtual by adding = 0 at the end, 
            it means that this function has no implementation in the current class. 

            It's a "pure" declaration that must be implemented by any concrete (i.e., non-abstract) derived class. 

            A class containing at least one pure virtual function is also called an Abstract class, 
            and you cannot create objects of an abstract class.
        */
};

class AdminRequestHandler : public RequestHandler {
    public:
        /*
            // Error: Cannot override final function 'Authenticate'
            bool Authenticate(const string& username, const string& password) override {
                // Admin-specific authentication logic here
                // ...
                return true;
            }
        */

        void HandleRequest(const string& endpoint) override {
            if (Authenticate("admin", "password123")) {
                cout << "Handling admin request for endpoint: " << endpoint << endl;
            } else {
                cout << "Authentication failed for admin request." << endl;
            }
        }
};

class UserRequestHandler : public RequestHandler {
    public:
        void HandleRequest(const string& endpoint) override {
            if (Authenticate("user", "userpassword")) {
                cout << "Handling user request for endpoint: " << endpoint << endl;
            } else {
                cout << "Authentication failed for user request." << endl;
            }
        }
};

/*
    In this example, we have a base class 'RequestHandler' that defines an 'Authenticate' function 
    for handling user authentication and a pure virtual 'HandleRequest' function for processing HTTP requests.

    The Authenticate function is marked as final because we want to ensure 
    that authentication is performed consistently across all derived classes.

    Derived classes like 'AdminRequestHandler' and 'UserRequestHandler' handle specific types of requests 
    but cannot override the authentication logic defined in the base class.
    
    This ensures that authentication remains consistent and cannot be accidentally modified in derived classes.
*/


int main() {

    system("clear");

    AdminRequestHandler adminHandler;
    UserRequestHandler userHandler;

    adminHandler.HandleRequest("/admin/dashboard");
    userHandler.HandleRequest("/user/profile");

    /*
        Question: Why instead of using final keyword we are not declaring 'Authenticate' as private?

        Answer: 
        1. final Keyword:
            When you mark a virtual function as final, you are explicitly stating that 
            this function should not be overridden by any further derived classes. 
            It enforces this constraint throughout the class hierarchy.

            While the function is still accessible to derived classes, 
            they cannot provide their own implementation of the function. 
            It's a way to explicitly communicate your intent to other developers that this function should remain unchanged.

        2. Private Function:
            When you declare a function as private, you are restricting access to the function entirely. 
            It cannot be accessed or overridden by derived classes.

            This approach is useful when you want to completely hide the function from any external or derived classes. 
            It's often used for internal implementation details that should not be part of the class's public interface.

        Choosing between final and private depends on your design goals:

        If you want to provide a consistent interface that derived classes can access but not modify, you use final. 
        It's a way to explicitly allow access while prohibiting further modifications.

        If you want to completely hide the function and prevent derived classes from even seeing it, you use private. 
        This is typically used for internal implementation details that should not be exposed.
    */
}
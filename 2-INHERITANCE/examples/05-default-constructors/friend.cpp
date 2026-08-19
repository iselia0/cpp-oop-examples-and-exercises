#include <iostream>

using namespace std;


/*
    Friend

    In C++, the friend keyword is used to declare a function or class as a friend of another class. 
    A friend function or class is granted access to the private and protected members of the class 
    it is declared as a friend of. 
    This is useful when you need to allow external functions or classes to access the private members of a class 
    without making those members public.
*/

class MyClass {
    private:
        int privateData;

    public:
        MyClass(int data) : privateData(data) {}

        // Declare the friend class
        friend class AnotherClass;

        // Declare the friend function
        friend void friendFunction(MyClass obj);
};


// Define the friend class
class AnotherClass {
    public:
        void accessPrivateData(MyClass obj) {
            // The friend class can also access private members of MyClass
            cout << "Friend Class: " << obj.privateData << endl;
        }
};


// Define the friend function
void friendFunction(MyClass obj) {
    cout << "Friend Function: " << obj.privateData << endl;
}


int main() {

    system("clear");
    
    MyClass myObject(42);

    // Call the friend function
    friendFunction(myObject);

    // Create an instance of the friend class and call its function
    AnotherClass friendObj;
    friendObj.accessPrivateData(myObject);

    return 0;
}
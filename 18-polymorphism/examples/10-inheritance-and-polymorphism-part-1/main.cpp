#include <iostream>

using namespace std;

/*
    Polymorphism

    10. Inheritance and Polymorphism with Static members
*/



/*
    1. Inheritance with Static Members:

    Static members (static variables and static methods) belong to the class itself, rather than to any instance of the class. 
    When you inherit from a base class, the derived class inherits the static members of the base class as well.
*/
class Base {
    public:
        static int staticVar;

        static void staticMethod() {
            cout << "Base static method" << endl;
        }

        /*
            2. Polymorphism with Static Members:

            Static members do not participate in polymorphism! 
            Polymorphism in C++ is based on the dynamic binding of virtual functions, 
            which applies only to instance (non-static) members.
        */
        virtual void virtualMethod() {
            cout << "Base virtual method" << endl;
        }
};

int Base::staticVar = 0;   // Initialize the static variable


class Derived : public Base {
    public:
        static void staticMethod() {
            cout << "Derived static method" << endl;
        }

        void virtualMethod() override {
            cout << "Derived virtual method" << endl;
        }
};
/*
    In this example, the Derived class inherits the staticVar and staticMethod() from the Base class. 
    You can access and modify the static members through the derived class as well as through the base class.
*/


int main() {

    system("clear");

    Derived::staticVar = 42;   // Access and modify the static variable through the Derived class

    cout << "Base staticVar: " << Base::staticVar << endl;   // Access staticVar through the base class
    cout << "Derived staticVar: " << Derived::staticVar << endl;   // Access staticVar through the derived class

    // Static method (no polymorphism)
    Base::staticMethod();   // Call the base class static method
    Derived::staticMethod();   // Call the derived class static method

    cout << "--------" << endl;

    // Virtual method (polymorphism)
    Base *ptr = new Derived();

    ptr->virtualMethod();   // Calls the derived class virtual method
    
    delete ptr;
    ptr = nullptr;   // nullptr safety
}
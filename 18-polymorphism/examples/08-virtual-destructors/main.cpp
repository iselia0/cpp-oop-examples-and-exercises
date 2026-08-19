#include <iostream>

using namespace std;

/*
    Polymorphism

    8. Virtual Destructors
*/

/*
    In C++, virtual destructors are a crucial concept when working with polymorphism 
    and inheritance to ensure proper cleanup of resources in a class hierarchy. 

    The Problem: 
        Without a virtual destructor in the base class, 
        if you delete a derived class object through a base class pointer, 
        only the base class destructor is called. 
        This can lead to incomplete cleanup if the derived class has allocated resources. 
        This is because the compiler doesn't know that the object is of a derived class and only calls the base class destructor.

    The Solution:
        By declaring the base class destructor as virtual, 
        you tell the compiler that it should use dynamic binding to call 
        the appropriate destructor for the actual derived class. 
        This ensures that the destructor chain is properly followed 
        through the inheritance hierarchy, and all resources are cleaned up correctly.
*/

class Base {
    public:
        Base() {
            cout << "Base: Constructor" << endl;
        }
        
        virtual ~Base() {
            cout << "Base: Destructor" << endl;
        }
};


class Derived : public Base {
    public:
        Derived() {
            container = new int[10];
            cout << "Derived: Constructor" << endl;
        }

        ~Derived() override {
            delete []container;
            cout << "Derived: Destructor" << endl;
        }

    private:
        int *container;
};



int main() {

    system("clear");

    Base *base = new Base();
    delete base;
    /*
        Output:

        Base: Constructor
        Base: Destructor
    */

    cout << "--------" << endl;

    Derived *derived = new Derived();
    delete derived;

    /*
        Output:

        Base: Constructor
        Derived: Constructor
        Derived: Destructor
        Base: Destructor

        Why in this order?
    */

    cout << "--------" << endl;

    Base *poly = new Derived();   // We have a polymorphic type
    delete poly;

    /*
        Without "virtual destructors" the output will be:

        Base: Constructor
        Derived: Constructor
        Base: Destructor

        As we can see, without virtual destructors, we do not call the derived class's destructor,
        which causes a memory leak (container).
        As because destructor method in the Base class is not virtual 
        the compiler does know that there might be a method down in hiearchy an override for destructors.


        With "virtual destructors" the output will be:

        Base: Constructor
        Derived: Constructor
        Derived: Destructor
        Base: Destructor
    */
}
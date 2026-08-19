#include <iostream>

using namespace std;

/*
    Polymorphism

    13. Polymorphic Functions and Destructors
*/


/*
    Do not call virtual(polymorphic) functions from constructors & destructors.

    But why?

    There are two main reasons why it is not right to call virtual functions inside constructors or destructors:

    1. Objects are constructed from the base up, but destroyed from the derived down. 
    This means that when a constructor is called, the derived class's members have not yet been initialized. 
    If the constructor calls a virtual function, the function from the base class will be called, 
    even if the derived class has overridden it. This can lead to unexpected behavior or even crashes.

    2. Virtual functions are not guaranteed to be virtual during construction and destruction. 
    C++ compilers are allowed to optimize virtual function calls during construction and destruction, 
    and this can include calling the base class's function instead of the derived class's function. 
    This means that even if you are careful to call the virtual function from the derived class's constructor, 
    there is no guarantee that the derived class's function will actually be called.
*/

// Here are the reasons why calling virtual functions from constructors and destructors is generally discouraged:

/*
    1. Virtual functions are not guaranteed to be resolved correctly: 
    When a constructor is called, the object is not fully constructed yet, 
    which means that the virtual function table (VMT) for the object may not be complete. 
    If you call a virtual function from a constructor, the compiler may resolve it 
    to the base class's implementation rather than the derived class's, leading to unexpected behavior.

    Example 1: 
*/
class Base {
    public:
        Base() {
            show();   // Calling a virtual function from the constructor
        }

        virtual void show() {
            cout << "Base class" << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {}

        void show() override {
            cout << "Derived class" << endl;
        }
};
/*
    Explanation:
    
    - In this example, we have a Base class and a Derived class that inherits from Base. 
    - Both classes have a virtual function show(). 
    - When we create an instance of Derived (i.e., Derived d;), the constructor of Base is automatically called, 
    which in turn calls the show() virtual function.
    - Now, you might expect that since we're creating an instance of Derived, 
    the show() function of Derived would be called. 
    - However, because the base class's constructor is calling the virtual function, and at that point, 
    the object is still in the process of being constructed as a Base object, 
    the show() function of the Base class is actually called instead.

    This is an example of how virtual functions can't guarantee the correct resolution when called from constructors!
*/



/*
    2. Virtual functions can lead to undefined behavior: 
    In a destructor, the object is already partially or fully destructed. 
    If you call a virtual function from a destructor, you may be trying to access 
    resources or data that have already been released, leading to undefined behavior, 
    such as crashes, memory corruption, or resource leaks.

    Example 2: 
*/
class Shape {
    public:
        Shape() {
            this->x = 0;
        }

        virtual ~Shape() {
            cout << "Shape Destructor!" << endl;
            this->printArea();
        }

        /*
         * virtual double calculateArea() const = 0;
         */

        virtual double calculateArea() const {
            return x * x;
        }

        void printArea() const {
            cout << "Area: " << this->calculateArea() << endl;
        }

    private:
        int x;
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        ~Circle() override {
            cout << "Circle Destructor!" << endl;
        }

        double calculateArea() const override {
            return 3.141592653589793 * radius * radius;
        }
};


int main() {

    system("clear");

    Derived obj1;   // Output: Base class

    cout << "-------" << endl;

    Shape *shape = new Circle(5.0);
    delete shape;
}

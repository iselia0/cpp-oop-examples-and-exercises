#include <iostream>

using namespace std;

/*
    Polymorphism

    16. Compile-Time Polymorphism and Run-Time Polymorphism
*/


/*
    Compile-time polymorphism and run-time polymorphism are two types of polymorphism in C++.

    There are two main types of polymorphism in C++: 
    - compile-time polymorphism (also known as static polymorphism) and 
    - run-time polymorphism (also known as dynamic polymorphism).
*/


/*
    1. Compile-Time Polymorphism (Static Polymorphism):

    Compile-time polymorphism is resolved by the C++ compiler at compile time, 
    hence the name "compile-time polymorphism."
    It is achieved through method overloading and operator overloading.

    a. Method Overloading:
*/
class Calculator {
    public:
        int add(int a, int b) {
            return a + b;
        }

        double add(double a, double b) {
            return a + b;
        }
};


/*
    In C++, you can define multiple functions or methods with the same name in a single class, 
    as long as they have different parameter listsMethod Overloading.
*/


/*
    b. Operator Overloading: 
    You can also overload operators (like +, -, *, <<, >>, /, %, == etc.) for user-defined classes,
    allowing you to define how these operators work for objects of your class.
*/
class Vector {
    private:
        double x;
        double y;

    public:
        Vector(double x, double y) : x(x), y(y) {}

        // Overload the - operator to subtract two vectors
        Vector operator - (const Vector& other) const {
            return Vector(x - other.x, y - other.y);
        }

        Vector operator + (const Vector& other) const {
            return Vector(x + other.x, y + other.y);
        }

        // Display the vector
        void display() const {
            cout << "(" << x << ", " << y << ")" << endl;
        }
};



/*
    2. Run-Time Polymorphism (Dynamic Polymorphism):
    
    Run-time polymorphism is resolved at runtime and is typically achieved through inheritance and virtual functions. 
    Here are the key aspects of run-time polymorphism:

    a. Inheritance: Run-time polymorphism relies on the concept of inheritance,
    where a derived class inherits properties and behaviors from a base class. 
    The derived class can override base class methods with its own implementations.
*/
class Animal {
    public:
        virtual void speak() {
            cout << "Animal makes a sound" << endl;
        }
};

class Dog : public Animal {
    public:
        void speak() override {
            cout << "Dog barks" << endl;
        }
};

class Cat : public Animal {
    public:
        void speak() override {
            cout << "Cat meows" << endl;
        }
};
        


int main() {

    system("clear");

    Calculator calc;
    int sum_int = calc.add(5, 10);           // Calls the int version of add()
    double sum_double = calc.add(3.5, 2.7);  // Calls the double version of add()


    Vector v1(3.0, 2.0);
    Vector v2(1.0, 1.0);

    // Use the overloaded - operator to subtract vectors
    Vector result = v1 - v2;

    cout << "Vector 1: ";
    v1.display();
    
    cout << "Vector 2: ";
    v2.display();

    cout << "Result: ";
    result.display();

    /*
        Output:

        Vector 1: (3, 2)
        Vector 2: (1, 1)
        Result: (2, 1)
    */
    cout << "-------" << endl;

    Dog dog;
    Cat cat;
    Animal *animals[] = {&dog, &cat};

    bool second;
    cin >> second;

    if (second) {
        animals[1]->speak();   // Calls Cat's speak() at runtime
    } else {
        animals[0]->speak();   // Calls Dog's speak() at runtime
    }

    /*
        Output:

        Dog barks
        Cat meows
    */
}
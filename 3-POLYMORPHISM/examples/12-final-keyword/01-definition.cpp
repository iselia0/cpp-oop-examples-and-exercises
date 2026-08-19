#include <iostream>

using namespace std;

/*
    Polymorphism

    12. Final
*/


/*
    Definition:

    In C++, the final keyword is used to indicate that a class, virtual function,
    or override cannot be further derived or overridden by other classes or functions. 
    
    It is used to enforce a level of inheritance control and is particularly useful when designing 
    class hierarchies that should not be extended or overridden beyond a certain point 
    for various reasons, such as security, stability, or design constraints.
*/


//  1. Final Classes:
class Base final {
    
};

class Derived : public Base {   // Error: base 'Base' is marked 'final'
    
};


// 2. Final Virtual Functions:
class Parent {
    public:
        virtual void call() final {
            // ...
        }
}; 

class Child : public Parent {
    public:
        void call() override {   // Error: declaration of 'call' overrides a 'final' function
            // ...
        }
};


int main() {

    system("clear");



}
#include <iostream>

using namespace std;

/*
    Polymorphism

    7. Overloading, overriding and function(method) hiding, Virtual Method Overloading
*/


/*
    1. Function Overloading:
    Function overloading allows you to define multiple functions with the same name 
    in the same scope but with different parameter lists. 
    The appropriate function to call is determined at compile-time based on the number or types of arguments.
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
    2. Function Overriding:
    Function overriding is a concept used in inheritance. 
    It allows a derived class to provide a specific implementation of a function that is already defined in its base class. 
    The overriding function must have the same name, return type, and parameters as the base class function.
*/
class Animal {
    public:
        virtual void speak() {
            cout << "Animal speaks." << endl;
        }
};

class Dog : public Animal {
    public:
        void speak() override {
            cout << "Dog barks." << endl;
        }
};

class Cat : public Animal {
    public:
        void speak() override {
            cout << "Cat muauws." << endl;
        }
};



/*
    3. Function Hiding:
    Function hiding occurs when a derived class defines a function 
    with the same name as a function in its base class but with a different parameter list. 
    Unlike function overriding, which requires the same parameter list, function hiding is not considered overriding.
*/
class Base {
    public:
        void display(int x) {
            cout << "Base: " << x << endl;
        }
};

class Derived : public Base {
    public:
        void display(double y) {
            cout << "Derived: " << y << endl;  
        }
};


const double PI = 3.14159265359;

class Shape {
    public:
        /*  Virtual Method Overloading  */
        virtual void area() const {
            cout << "Shape area: " << 0.0 << endl;
        }

        virtual void area(int area) const {
            cout << "Shape area: " << area << endl;
        }
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        /*  Virtual Method Overloading  */
        void area() const override {
            cout << "Circle area: " << 2 * (PI * 0.0 * 0.0) << endl;
        }

        void area(int radius) const override {
            cout << "Circle area: " << 2 * (PI * radius * radius) << endl;
        }
};


class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle() : width(1), height(1) {}
        Rectangle(double w, double h) : width(w), height(h) {}

        /*
            One overriden overload hides all the others!!!
        */
        virtual void area() const override {
            cout << "Rectangle area: " << (width * height) << endl;    // Area of a rectangle
        }
};

class Square : public Rectangle {
    private:
        double sideLength;

    public:
        Square(double s) : sideLength(s) {}

        /*
            One overriden overload hides all the others in the base class !!!
        */
        virtual void area() const override {
            cout << "Square area: " << (sideLength * sideLength) << endl;    // Area of a square
        }
};


int main() {

    system("clear");

    Shape shape;
    Circle circle(2.0);
    Rectangle rectangle(10, 5);
    Square square(4);

    circle.area();      // Circle area: 0
    circle.area(44);    // Circle area: 12164.2

    rectangle.area();   // Rectangle area: 50
    // rectangle.area(44);     // Error

    square.area();
    // square.area(44);    // Error
}
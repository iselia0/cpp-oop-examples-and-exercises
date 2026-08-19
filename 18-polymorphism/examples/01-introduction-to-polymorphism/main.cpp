#include <iostream>

using namespace std;

/*
    Polymorphism

    1. Introduction to Polymorphism
    2. Static Binding with Inheritance
    3. Dynamic binding with virtual functions
    4. Size of polymorphic objects and slicing
    5. Polymorphic objects stored in collections (array)
    6. Override
    7. Overloading, overriding and function hiding
    8. Virtual Destructors
    9. Static Keyword in C++
    10. Inheritance and Polymorphism at different levels
    11. Inheritance and polymorphism with static members 
    12. Final
    13. Polymorphic Functions and Destructors
    14. Pure virtual functions and abstract classes
    15. Abstract Classes as Interfaces
    16. Compile time polymorphism and run time polymorphism
*/


/*
    Definition:

    Polymorphism in OOP is the ability of different objects to respond 
    to the same method or function in a way that is specific to their individual types.

    Imagine you have different shapes, like Circles, Squares, and Triangles, and you want to calculate their areas. 
    In a program using Polymorphism, you can have a single "calculateArea" method, 
    and each shape (object) can provide its own unique implementation of that method. 
    So when you call "calculateArea" on a Circle object, it calculates the circle's area, 
    and when you call it on a Square object, it calculates the square's area, all using the same method name.
*/


/*   Example   */
class Shape {
    public:
        // This function is marked as Virtual to enable Polymorphism.
        virtual double calculateArea() {
            return 0.0;   // Default implementation for unknown shapes
        }
};


class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        double calculateArea() override {
            return 3.14159265359 * radius * radius;    // Area of a circle
        }
};


class Square : public Shape {
    private:
        double sideLength;

    public:
        Square(double s) : sideLength(s) {}

        double calculateArea() override {
            return sideLength * sideLength;    // Area of a square
        }
};


class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle(double w, double h) : width(w), height(h) {}

        double calculateArea() override {
            return width * height;    // Area of a square
        }
};



int main() {

    system("clear");

    // Recall this option
    int a = 5, b = 6, c = 7;
    int *elements[] = {&a, &b, &c};    // array of pointers for integer type

    cout << elements[0] << ": " << *elements[0] << endl;
    cout << elements[1] << ": " << *elements[1] << endl;
    cout << elements[2] << ": " << *elements[2] << endl;
    
    cout << "-------" << endl;

    // note the polymorphism here
    Shape *shape1 = new Circle(1.2);
    Shape *shape2 = new Square(8.4);
    Shape *shape3 = new Rectangle(0.4, 9.3);

    // or here
    Shape &ref1 = *shape1;
    Shape &ref2 = *shape2;
    Shape &ref3 = *shape3;

    cout << "Area of Circle:    " << ref1.calculateArea() << endl;
    cout << "Area of Square:    " << ref2.calculateArea() << endl;
    cout << "Area of Rectangle: " << ref3.calculateArea() << endl;
    cout << "-------" << endl;

    // Release memory
    delete shape1;
    shape1 = nullptr;

    delete shape2;
    shape2 = nullptr;

    delete shape3;
    shape3 = nullptr;


    // Array of Shape pointers
    Circle circle(5.0);
    Square square(4.0);
    Rectangle rectangle(2.0, 3.4);

    // Store them in an array of Shape pointers
    Shape *shapes[] = { &circle, &square, &rectangle };

    // Calculate and display the areas using Polymorphism
    for (Shape *shape : shapes) {
        cout << "Area: " << shape->calculateArea() << endl;  
    }
}

/*
    Benefits

    1. Code Reliability: Polymorphism allows you to write generic code that can work with objects of various derived classes.
    This promotes code usability because you can create new classes that conform to the same base class interface and use them with existing code.

    2. Flexibility and Extensibility: Polymorphism makes your code more flexible and extensible. 
    You can add new derived classes without modifying existing code that interacts with the base class. 
    This reduces the risk of introducing bugs when extending your software.

    3. Simplifies Code: Polymorphism simplifies code by providing a common interface for objects of different types. 
    This reduces the need for conditional statements and switch cases, making the code easier to read and maintain.

    4. Enhances Maintainability: Because polymorphism encourages a clean separation of concerns 
    between base and derived classes, it makes your codebase more organized and easier to maintain. 
    Changes to one class don't necessarily impact other parts of the code.

    5. Enables Dynamic Binding: Polymorphism enables dynamic binding (also known as late binding or runtime binding). 
    This means that the appropriate method implementation is determined at runtime based on the actual object type, 
    rather than at compile time. This flexibility is crucial for certain design patterns and scenarios.

    6. Supports Abstraction: Polymorphism encourages the use of abstract base classes with pure virtual functions. 
    These abstract classes provide a high level of abstraction, 
    allowing you to define a common interface without specifying implementation details. 
    This can improve the clarity of your code's architecture.
*/
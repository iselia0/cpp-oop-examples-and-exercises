#include <iostream>
#include <string>

using namespace std;


/*
    Exercise: Polymorphism in C++

    Instructions:

    1. Create a C++ program that models geometric shapes.
    2. Define a base class Shape with the following properties and methods:
        Properties:
        name (string): The name of the shape.
        Methods:
        virtual void draw(): A virtual function that prints a message indicating that a shape is being drawn.
        The message should include the shape's name.
    3. Create two derived classes, Circle and Rectangle, that inherit from the Shape class. 
    Each derived class should have its own specific properties and methods:
        Circle:
        Properties:
        radius (double): The radius of the circle.
        Methods:
        Override the draw() method to print a message indicating that a circle is being drawn, along with its radius.
        Rectangle:
        Properties:
        length (double): The length of the rectangle.
        width (double): The width of the rectangle.
        Methods:
        Override the draw() method to print a message indicating that a rectangle is being drawn, along with its length and width.
    4. In the main() function, create instances of the Circle and Rectangle classes.
    5. Create an array of pointers to Shape objects and store the addresses of the Circle and Rectangle objects in the array.
    6. Use a loop to iterate through the array and call the draw() method for each object. 
    Observe how polymorphism allows you to call the appropriate draw() method based on the actual type of the object.
    7. Compile and run the program to verify that the correct messages are printed for each shape.

    Example Output:
    Drawing a circle with radius 5.0
    Drawing a rectangle with length 6.0 and width 4.0

    8. Challenge: Extend the program by adding more derived classes (e.g., Triangle, Square) 
    and further explore polymorphism by creating objects of these classes and adding them to the array of shapes. 
    Update the draw() methods in the derived classes accordingly.
*/

// Solution:
class Shape {
    public:
        string name;

        Shape(const string& shapeName) : name(shapeName) {}

        virtual void draw() {
            cout << "Drawing a " << name << endl;
        }
};

// Derived class 1: Circle
class Circle : public Shape {
    public:
        double radius;

        Circle(const string& circleName, double circleRadius) : Shape(circleName), radius(circleRadius) {}

        void draw() override {
            cout << "Drawing a circle with radius " << radius << endl;
        }
};

// Derived class 2: Rectangle
class Rectangle : public Shape {
    public:
        double length;
        double width;

        Rectangle(const string& rectangleName, double rectLength, double rectWidth) 
        : Shape(rectangleName), length(rectLength), width(rectWidth) {}

        void draw() override {
            cout << "Drawing a rectangle with length " << length << " and width " << width << endl;
        }
};

// Derived class 3: Triangle
class Triangle : public Shape {
    public:
        double base;
        double height;

        Triangle(const string& triangleName, double triBase, double triHeight) : Shape(triangleName), base(triBase), height(triHeight) {}

        void draw() override {
            cout << "Drawing a triangle with base " << base << " and height " << height << endl;
        }
};

// Derived class 4: Square
class Square : public Shape {
    public:
        double side;

        Square(const string& squareName, double squareSide) : Shape(squareName), side(squareSide) {}

        void draw() override {
            cout << "Drawing a square with side " << side << endl;
        }
};


int main() {

    /*      Example usage:     */ 

    Circle circle("Circle", 5.0);
    Rectangle rectangle("Rectangle", 6.0, 4.0);
    Triangle triangle("Triangle", 4.0, 3.0);
    Square square("Square", 5.0);

    Shape* shapes[] = { &circle, &rectangle, &triangle, &square };

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
    }

    return 0;
}

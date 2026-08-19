#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    15. Abstract Classes as Interfaces
*/


/*
    Definition:

    Abstract Classes:
    1. An abstract class is a class that cannot be instantiated on its own; 
    it serves as a blueprint for other classes.
    2. Abstract classes can have both concrete (implemented) and abstract (pure virtual) member functions.
    3. Abstract classes may also have member variables and constructors.
    4. Derived classes must implement all pure virtual functions defined in the abstract class 
    in order to become concrete classes themselves (otherwise they become abstract classes themselves).

    Interfaces:
    1. In C++, there is no built-in construct called an "interface" 
    like in some other programming languages (e.g., Java, Php or C#).
    2. However, you can simulate interfaces by defining abstract classes containing 
    only pure virtual functions, effectively creating a contract that derived classes must implement.


    Differences:

    Abstract Class:
    - An abstract class can have both method implementations (concrete methods) 
      and pure virtual methods (methods without implementations).
    - It can also have member variables and constructors.
    - Derived classes must provide implementations for the pure virtual methods.
    - It allows for some shared functionality among derived classes.

    Interface:
    - An interface contains only pure virtual methods (methods without implementations).
    - It cannot have member variables or constructors.
    - Classes implementing an interface must provide implementations for all the methods in the interface.
    - It defines a contract without any shared implementation.

    In summary, an abstract class can have both implemented and unimplemented methods 
    and may contain member variables, while an interface contains only unimplemented methods, 
    defining a pure contract without any shared implementation.
*/


// Abstract Class: Shape
class Shape {
    public:
        Shape() {
            this->name = "Generic Shape";
        }
        
        // Pure virtual function
        virtual double area() const = 0;
        
        // Concrete function
        void displayArea() const {
            cout << "Area: " << area() << endl;
        }
        
        // Abstract class can have member variables
        void printShape() const {
            cout << name << endl;
        }

        string getName() const {
            return name;
        }
        
    protected:
        string name;
};


// Interface: Drawable
class Drawable {
    public:
        virtual void draw() const = 0;
};


// Concrete Class: Circle
class Circle : public Shape, public Drawable {
    public:
        Circle(double radius) : radius(radius) {
            name = "Circle";
        }

        // Implementing the pure virtual function from Shape
        double area() const override {
            return 3.14159 * radius * radius;
        }
        
        // Implementing the pure virtual function from Drawable
        void draw() const override {
            printShape();   // using the abstract class method
            cout << "Drawing a circle." << endl;
        }
        
    private:
        double radius;
};


// Concrete Class: Rectangle
class Rectangle : public Shape, public Drawable {
    public:
        Rectangle(double width, double height) : width(width), height(height) {
            name = "Rectangle";
        }
        
        // Implementing the pure virtual function from Shape
        double area() const override {
            return width * height;
        }
        
        // Implementing the pure virtual function from Drawable
        void draw() const override {
            cout << "Drawing a rectangle." << endl;
        }
        
    private:
        double width;
        double height;
};


int main() {
    
    system("clear");

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    
    cout << circle.getName() << " Area: " << circle.area() << endl;
    circle.displayArea();
    circle.draw();
    
    cout << rectangle.getName() << " Area: " << rectangle.area() << endl;
    rectangle.displayArea();
    rectangle.draw();


    /*
        Key Differences:
            - Shape is an abstract class that includes both pure virtual and concrete functions, as well as a member variable.
            - Drawable is an interface that includes only a pure virtual function.
            - Circle and Rectangle implement both the Shape and Drawable concepts, 
              providing implementations for their respective pure virtual functions.
    */
    
}
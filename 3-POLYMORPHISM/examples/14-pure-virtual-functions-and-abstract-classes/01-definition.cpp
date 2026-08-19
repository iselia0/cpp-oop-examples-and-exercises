#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    14. Pure virtual functions and Abstract classes
*/


/*
    Definition:

    A pure virtual function is a virtual function that does not have an implementation. 
    It is declared with a pure specifier, which is an equals sign followed by a zero ( = 0 ).

    An abstract class is a class that contains at least one pure virtual function. 
    Abstract classes cannot be instantiated, but they can be used as base classes for other classes.

    Pure virtual functions and abstract classes are used to implement polymorphism in C++. 
    Polymorphism is a feature that allows objects of different types to be treated in a similar way.
*/


class Shape {
    protected:
        Shape() = default;
        Shape(string_view p_description) : description(p_description) {}

    public:
        // If destructor is not public, you won't be able to delete base pointer. Why?
        virtual ~Shape() = default; 

        // Pure virtual function makes this class abstract.
        virtual double perimeter() const = 0;
        virtual double surface() const = 0;

    private:
        string description;
};


class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle() = default;
        Rectangle(double w, double h, string_view description) : width(w), height(h), Shape(description) {}

        virtual ~Rectangle() = default;

        // Implementing the pure virtual function
        virtual double perimeter() const override {
            return 2 * (width + height);
        }

        virtual double surface() const override {
            return (width * height);
        }
};


class Circle : public Shape {
    private:
        double radius;
        const double PI = 3.14159265359;

    public:
        Circle() = default;
        Circle(double r, string_view description) : radius(r), Shape(description) {}

        virtual ~Circle() = default;

        virtual double perimeter() const override {
            return 2 * (PI + radius);
        }

        /*
            If we don't override one of the pure virtual functions from the Shape(base) class, 
            the Circle(derived) class will itself become an abstract class, 
            which will result in a compile-time error when creating an instance (object) of that class.
            
            Error: allocating an object of abstract class type 'Circle'

            But why?
        */
        virtual double surface() const override {
            return PI * radius * radius;
        }

};



int main() {

    system("clear");
    
    // Shape *shape = new Shape();   // Error: allocating an object of abstract class type 'Shape'
    
    const Shape *shape_rect = new Rectangle(10, 10, "rectangle");

    cout << "Rectangle perimeter: " << shape_rect->perimeter() << endl;
    cout << "Rectangle surface: " << shape_rect->surface() << endl;

    cout << "--------" << endl;


    const Shape *shape_circle = new Circle(10, "circle");

    cout << "Circle perimeter: " << shape_circle->perimeter() << endl;
    cout << "Circle surface: " << shape_circle->surface() << endl;
    
    /*
        Summary:

        1. If a class has at least one pure virtual function, it becomes
        abstract class.

        2. You can't create objects of an abstract class, if you do you'll get
        serious compiler error.

        3. Derived classes of an abstract class must explicitly override all pure
        virtual functions of the abstract parent class, otherwise
        they themselves become abstract.

        4. Pure virtual functions have no implementation in an abstract class.
        They are intended to be implemented through class inheritance.
        You cannot call pure virtual functions from a constructor abstract class 
        because we do not have implementation of these things.
        
        5. The abstract class constructor is used by the derived class to
        creating the base part of the object.
    */
}
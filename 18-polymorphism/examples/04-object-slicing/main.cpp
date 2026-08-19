#include <iostream>

using namespace std;

/*
    Polymorphism

    4. Size of polymorphic objects and slicing
*/

class Shape {
    public:
        virtual void area() const {
            cout << "Shape area: " << 0.0 << endl;
        }
};


class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        void area() const {
            cout << "Circle area: " << (3.14159265359 * radius * radius) << endl;   // Area of a circle
        }
};


class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle() : width(1), height(1) {}
        Rectangle(double w, double h) : width(w), height(h) {}

        void area() const {
            cout << "Rectangle area: " << (width * height) << endl;    // Area of a rectangle
        }

        void non_virtual_method() const {}
};


class Square : public Rectangle {
    private:
        double sideLength;

    public:
        Square(double s) : sideLength(s) {}

        void area() const {
            cout << "Square area: " << (sideLength * sideLength) << endl;    // Area of a square
        }
};


int main() {

    system("clear");

    Shape shape;
    Circle circle(2.0);
    Square square(4);
    Rectangle rectangle(10, 5);


    cout << "Without Virtual Methods: " << endl;
    cout << sizeof(shape) << endl;       // static: 1 byte
    cout << sizeof(circle) << endl;      // static: 8 byte
    cout << sizeof(square) << endl;      // static: 32 byte
    cout << sizeof(rectangle) << endl;   // static: 16 byte 

    cout << "----------" << endl;

    cout << "With Virtual Methods: " << endl;
    cout << sizeof(shape) << endl;       // dynamic: 8 byte
    cout << sizeof(circle) << endl;      // dynamic: 16 byte
    cout << sizeof(square) << endl;      // dynamic: 32 byte
    cout << sizeof(rectangle) << endl;   // dynamic: 24 byte

    /*
        Why with Dynamic Polymorphism our objects are going to be much larger?

        Answer:

        Virtual Function Tables (VTables): In C++, dynamic polymorphism relies on VTables, 
        which are tables of function pointers associated with each class that contains virtual functions. 
        These VTables enable the program to determine at runtime which version of a virtual function 
        to call based on the actual type of the object. 
        Each object that has virtual functions typically contains a pointer to its VTable.
        This VTable pointer adds some overhead to the object's size.

        Source: https://pabloariasal.github.io/2017/06/10/understanding-virtual-tables/
    */

    cout << "----------" << endl;


    /* _______ Slicing _______ */ 
    Rectangle rect(200, 300);
    Shape shape1 = rect;    // here happens our slicing

    shape1.area();   // Shape: area

    /*
        As you can see above, the "Shape shape1 = rect" code doesn't give us an error 
        because the rectangle is a shape, so we can assign it.
        But slicing happens here because the rectangle has more attributes than the raw shape 
        (the rectangle has "width" and "height" information).
        But the compiler trying to assign a rect to the shape1 object will be smart enough 
        that we don't need the width and height information in our shape object.
    */
}
#include <iostream>

using namespace std;

/*
    Polymorphism

    5. Polymorphic objects stored in collections (array)
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

    // Objects sliced off!   why?
    Shape shapes[] = {circle, square, rectangle};   // after assigning the data lost permanently

    for (const Shape &shape : shapes) {
        shape.area();
    } 
    
    cout << "---------" << endl;


    // Raw pointers (no slicing)
    Shape *pShapes[] = {&circle, &square, &rectangle};

    for (auto &shape : pShapes) {
        shape->area();
    }

    /*
        [Output]
        
        Shape area: 0
        Shape area: 0
        Shape area: 0
        ---------
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
    */

}
#include <iostream>

using namespace std;

/*
    Polymorphism

    2. Static Binding with Inheritance
*/


class Shape {
    public:
        void area() const {
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
    shape.area();

    Circle circle(2.0);
    circle.area();

    Square square(4);
    square.area();

    Rectangle rectangle(10, 5);
    rectangle.area();
    
    cout << "-------" << endl;


    // Static binding with base class Pointer
    Shape *shapes = &shape;
    (*shapes).area();   // Shape area: 0.0

    shapes = &circle;
    (*shapes).area();   // Shape area: 0.0,    but would wish Circle::area()

    shapes = &square;
    shapes->area();     // Shape area: 0.0,    but would wish Square::area()

    shapes = &rectangle;
    shapes->area();     // Shape area: 0.0,    but would wish Rectangle::area()

    /*
        Why can we store different types of objects in a shape pointer like a circle?

        Answer: A circle is a shape according to our inheritance hierarchy.
        For example, a square is a shape because it is derived from a rectangle, 
        and a rectangle is also a shape according to our inheritance hierarchy.
    */
    
    cout << "-------" << endl;


    // Static binding with base class Reference
    Shape &rShape1 = shape;
    rShape1.area();    // Shape area: 0.0

    Shape &rShape2 = circle;
    rShape2.area();    // Shape area: 0.0,    but would wish Circle::area()

    Shape &rShape3 = square;
    rShape3.area();    // Shape area: 0.0,    but would wish Square::area()

    Shape &rShape4 = rectangle;
    rShape4.area();    // Shape area: 0.0,    but would wish Rectangle::area()

    /*
        The compiler just looks at the 'pointer' or 'reference' type to decide which area() version to call.
        It sees 'Shape*' or 'Shape&' and calls Shape::area().
        This is static binding in an action!
    */


    /*
        Shapes stored in a collection
    */
    Circle circles[] = {Circle(1.5), Circle(2.4), Circle(4.6)};
    Rectangle rectangles[] = {Rectangle(-3, -5), Rectangle(4.5, 5.4), Rectangle(0.5, 0.4), Rectangle(4, 5)};
    
    Shape shapeObjects[] = {Circle(2.4), Rectangle(4.5, 5.4)};   // What we are losing in this case? will it help you?
    // More arrays as you have more shapes right? 
    // what you will do you'll have 50 shapes?

    /*
        [Output]

        Shape area: 0
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
        -------
        Shape area: 0
        Shape area: 0
        Shape area: 0
        Shape area: 0
        -------
        Shape area: 0
        Shape area: 0
        Shape area: 0
        Shape area: 0
    */
}

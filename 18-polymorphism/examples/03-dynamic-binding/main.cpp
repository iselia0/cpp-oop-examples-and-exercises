#include <iostream>

using namespace std;

/*
    Polymorphism

    3. Dynamic binding with virtual functions (polymorphism)
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

        virtual void area() const {
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

        virtual void area() const {
            cout << "Rectangle area: " << (width * height) << endl;    // Area of a rectangle
        }

        void non_virtual_method() const {}
};


class Square : public Rectangle {
    private:
        double sideLength;

    public:
        Square(double s) : sideLength(s) {}

        virtual void area() const {
            cout << "Square area: " << (sideLength * sideLength) << endl;    // Area of a square
        }
};


// Universal function
void shape_area(const Shape *const shape) {
    shape->area();
}

// Universal function
void shape_area_ref(const Shape &shape) {
    shape.area();
}


int main() {

    system("clear");

    Shape shape;
    shape.area();

    Circle circle(2.0);
    circle.area();

    Circle circle2(4.0);
    circle.area();

    Square square(4);
    square.area();

    Rectangle rectangle(10, 5);
    rectangle.area();
    
    cout << "-------" << endl;


    // Dynamic binding with virtual functions (polymorphism)
    Shape *shapes = &shape;

    (*shapes).area();   // Shape area: 0.0

    shapes = &circle;
    (*shapes).area();   // Circle::area()

    shapes = &square;
    shapes->area();     // Square::area()

    shapes = &rectangle;
    shapes->area();     // Rectangle::area()

    // Error: no member named 'non_vitual_method' in 'Shape'
    // shapes->non_vitual_method();
    
    cout << "-------" << endl;


    // Dynamic binding with virtual functions (polymorphism)
    Shape &rShape1 = shape;
    rShape1.area();    // Shape area: 0.0

    Shape &rShape2 = circle;
    rShape2.area();    // Circle::area()

    Shape &rShape3 = square;
    rShape3.area();    // Square::area()

    Shape &rShape4 = rectangle;
    rShape4.area();    // Rectangle::area()

    cout << "-------" << endl;


    // Show Area through universal function
    shape_area(&shape);
    shape_area(&circle);
    shape_area(&square);
    shape_area(&rectangle);

    cout << "-------" << endl;


    // Show Area through universal function
    shape_area_ref(shape);
    shape_area_ref(circle);
    shape_area_ref(square);
    shape_area_ref(rectangle);

    cout << "-------" << endl;


    Shape *collection[] = {&shape, &circle, &circle2, &square, &rectangle};

    for (const Shape *const shape : collection) {
        shape->area();
    }

    /*
        [Output]

        Shape area: 0
        Circle area: 12.5664
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
        -------
        Shape area: 0
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
        -------
        Shape area: 0
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
        -------
        Shape area: 0
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
        -------
        Shape area: 0
        Circle area: 12.5664
        Square area: 16
        Rectangle area: 50
        -------
        Shape area: 0
        Circle area: 12.5664
        Circle area: 50.2655
        Square area: 16
        Rectangle area: 50
    */

}
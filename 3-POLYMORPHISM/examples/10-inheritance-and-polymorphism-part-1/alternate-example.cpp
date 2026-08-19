#include <iostream>

using namespace std;

/*
    Polymorphism

    10. Inheritance and Polymorphism with Static members
*/


class Shape {
    public:
        static int count;

        Shape() {
            ++count;
        }

        virtual ~Shape() {
            --count;
        }

        virtual void area() const {
            cout << "Shape area: " << 0.0 << endl;
        }
};


class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        virtual void area() const override {
            cout << "Circle area: " << (3.14159265359 * radius * radius) << endl;   // Area of a circle
        }
};


class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        // Rectangle will have it is own static member called count despite it is in shape also
        static int count;

        Rectangle() : width(1), height(1) {
            ++count;
        }

        Rectangle(double w, double h) : width(w), height(h) {
            ++count;
        }

        ~Rectangle() {
            --count;
        }

        virtual void area() const override {
            cout << "Rectangle area: " << (width * height) << endl;    // Area of a rectangle
        }
};


// initialization of static members
int Shape::count = 0;
int Rectangle::count = 0;


int main() {

    system("clear");

    Shape shape_1;
    cout << "shape count: " << Shape::count << endl;    // 1

    Shape shape_2;
    cout << "shape count: " << Shape::count << endl;    // 2

    Shape shape_3;
    cout << "shape count: " << Shape::count << endl;    // 3

    {
        {
            Shape shape_4;
            cout << "shape count: " << Shape::count << endl;    // 4
        }

        cout << "shape count: " << Shape::count << endl;    // 3,  Why?
    }
    
    cout << "--------" << endl;

    Circle circle_1(1.5);
    cout << "shape count: " << Shape::count << endl;    // 4
    cout << "circle count: " << Circle::count << endl;  // 4, Why? Because the circle is also a shape

    cout << "--------" << endl;

    Rectangle rectangle_1;
    cout << "shape count: " << Shape::count << endl;   // 5
    cout << "rectangle count: " << Rectangle::count << endl;  // 1, Why? Because Rectangle class has it is own static count
    
}




#include <iostream>

using namespace std;

/*
    Polymorphism

    6. Override
*/


/*
    The "override" keyword is used as part of the function declaration in the derived class 
    to explicitly indicate that you intend to override a virtual function from the base class.

    Override:
    1. It is used for clarity and to inform the compiler that you intend to provide 
    a new implementation for a virtual method inherited from the base class.
    2. If you use "override" in a derived class method but there's no matching virtual method in the base class, 
    the compiler will generate an error (which is very useful property to avoid type in methods name).


    Do I need to write "override" if virtual methods by their nature tend to be overwritten?

    Answer:
    While It's not strictly necessary to use the override keyword when overriding virtual methods in C++, 
    it is considered good practice to include it for the following reasons:

    1. To make your code more readable and maintainable. 
    The override keyword tells the reader of your code that you are intentionally overriding a virtual method, 
    which can help to prevent errors.

    2. Compile-Time Checks: When you use override, 
    the compiler performs additional checks to ensure that the method in the derived class 
    indeed overrides a virtual function from the base class. 
    If there is a mistake in the method signature (e.g., a typo in the method name or a mismatch in parameters), 
    the compiler will generate an error. Without override, 
    such errors might go unnoticed and result in unexpected behavior.

    3. Documentation: It serves as documentation for your code. 
    It's a clear indicator that the method is expected to be an override, 
    even for developers who may not be intimately familiar with the base class.

    4. Maintenance: If you or someone else later changes the base class method signature, 
    the compiler will warn you about any derived classes that need to be updated if you've used override. 
    Without it, you might accidentally fail to update the derived class, leading to subtle bugs.

    In summary, while it's not mandatory to use override, 
    it's strongly recommended for the sake of code clarity, safety, and maintainability.
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

        /*
            There is a potential issue with the method name or a mismatch in parameters, 
            but the compiler won't produce an error because we haven't used the 'override' keyword.
        */
        virtual void area() const override {
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

        /*
            The compiler will report an error due to the 'override' keyword.
            This is because we've mistakenly used 'Area' instead of 'area,' 
            which doesn't exist in the base class (Shape).
            Attempting to override a non-existing method ('Area') will result in an error.

            [Error]: 'Area' marked 'override' but does not override any member functions virtual void Area() const override
        */
        virtual void Area() const override {
            cout << "Rectangle area: " << (width * height) << endl;    // Area of a rectangle
        }

        void non_virtual_method() const {}
};


class Square : public Rectangle {
    private:
        double sideLength;

    public:
        Square(double s) : sideLength(s) {}

        virtual void area() const override {
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

    for (Shape &shape : shapes) {
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
#include <iostream>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Implement static methods within the Circle and Rectangle classes 
    to calculate the areas of circles and rectangles, respectively. 
    Additionally, create a static method in the Shape class to compare the areas of two shapes.

    Tasks:

    1. Implement the CalculateArea static methods in the Circle and Rectangle classes to calculate the areas of circles and rectangles, respectively.
    2. Create a static method in the Shape class to compare the areas of two shapes. You'll need to access the CalculateArea static methods in the derived classes for this comparison.
    3. In the main function, prompt the user to enter the radius for a circle and the width and height for a rectangle.
    4. Calculate and display the areas of the circle and rectangle using the static methods.

    Implement comparisons of areas using the static method in the Shape class to determine if the areas are equal.
*/

class Shape {
    public:
        // Static method to compare the areas of two shapes
        // Hint: You'll need to access the CalculateArea static methods in the derived classes.
        static bool CompareAreas(const Shape& shape1, const Shape& shape2) {
            double area1 = shape1.CalculateArea();
            double area2 = shape2.CalculateArea();
            return area1 == area2;
        }

        virtual double CalculateArea() const {
            return 0.0;
        }
};


class Circle : public Shape {
    public:
        Circle(double radius) : radius(radius) {}

        // Static method to calculate the area of a circle
        // Hint: Use the formula for calculating the area of a circle (A = π * r^2)

        // Static method to calculate the area of a circle
        static double CalculateArea(double radius) {
            return 3.14159 * radius * radius;
        }

        // Override the virtual method to calculate the area of the circle
        double CalculateArea() const override {
            return CalculateArea(radius);
        }

    private:
        double radius;
};


class Rectangle : public Shape {
    private:
        double width, height;

    public:
        Rectangle(double width, double height) : width(width), height(height) {}

        // Static method to calculate the area of a rectangle
        // Hint: Use the formula for calculating the area of a rectangle (A = width * height)

        // Static method to calculate the area of a rectangle
        static double CalculateArea(double width, double height) {
            return width * height;
        }

        // Override the virtual method to calculate the area of the rectangle
        double CalculateArea() const override {
            return CalculateArea(width, height);
        }
};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    // Calculate and display the areas using the static methods

    // Implement comparisons of areas using the static method in the Shape class

    return 0;
}
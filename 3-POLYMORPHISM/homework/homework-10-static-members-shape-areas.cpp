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
        static bool CompareAreas(double area1, double area2){
            return area1==area2;
         }
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double radius) : radius(radius) {}

        static double CalculateArea(double radius){
            return 3.14*radius*radius;
        }

        // Static method to calculate the area of a circle
        // Hint: Use the formula for calculating the area of a circle (A = π * r^2)
};

class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double width, double height) : width(width), height(height) {}
        
        static double CalculateArea(double width, double height){
            return width*height;
        }
        // Static method to calculate the area of a rectangle
        // Hint: Use the formula for calculating the area of a rectangle (A = width * height)
        
        double getWidth() const {return width;}
        double getHeight() const {return height;}

};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width and height of a rectangle: ";
    cin >> rectWidth >> rectHeight;

    // Calculate and display the areas using the static methods

    // Implement comparisons of areas using the static method in the Shape class

    double circleArea=Circle::CalculateArea(circleRadius);
    double rectArea=Rectangle::CalculateArea(rectWidth, rectHeight);

    cout<<"Circle area:"<<circleArea<<endl;
    cout<<"Rectangle area:"<<rectArea<<endl;

    if(Shape::CompareAreas(circleArea, rectArea)){
        cout<<"Equal areas"<<endl;
    } 
    else{
        cout<<"Not equal areas"<<endl;
    }

    return 0;
}
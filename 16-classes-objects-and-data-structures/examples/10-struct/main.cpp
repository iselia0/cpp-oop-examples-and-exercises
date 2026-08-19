#include <iostream>
#include <string>

using namespace std;


/*
    11. Struct

    Struct is a user-defined data type that allows you to group together 
    different variables of different types into a single unit. 
    It is similar to a class but with default public access for its members.
    Struct can also have methods (functions) associated with it
*/


// Members private by default
class Dog {
    string name = "None";
};

// Members public by default
struct Cat {
    string name;
};


// Common use for struct
struct Point {
    double x;
    double y;
};



// Here's an example of a struct with methods:
struct Rectangle {
    private:
        double length;
        double width;

    public:
        Rectangle(double length, double width) {
            this->length = length;
            this->width = width;
        }

        // Method to calculate the area of the rectangle
        double calculateArea() {
            return length * width;
        }

        // Method to calculate the perimeter of the rectangle
        double calculatePerimeter() {
            return 2 * (length + width);
        }
};


int main() {
    Rectangle rectangle(5.0, 3.0);

    // Use the struct methods to perform calculations
    double area = rectangle.calculateArea();
    double perimeter = rectangle.calculatePerimeter();

    // Print the results
    cout << "Rectangle Area: " << area << endl;
    cout << "Rectangle Perimeter: " << perimeter << endl;

    /*
        Differences between structures and classes?

        1. Default Access Specifier: In a struct, the default access specifier for its members is public,
        which means that all members are accessible from outside the struct without any access restrictions. 
        In contrast, the default access specifier for class members is private, 
        requiring explicit access control (public, private, or protected) for each member.

        2. Usage Convention: In C++, the usage convention for structs is often centered 
        around simple data containers, grouping related data members together. 
        Structs are commonly used when the focus is on data rather than behavior. 
        On the other hand, classes are often used for more complex objects that encapsulate data and behavior. 
        Classes allow for the use of access modifiers and provide more flexibility 
        in designing and implementing object-oriented features such as encapsulation, data hiding, and polymorphism.

        3. Inheritance: When deriving a class or struct from another class or struct, 
        there is a difference in the default inheritance access specifier. 
        For a struct, the default inheritance access specifier is public, 
        which means that the derived struct inherits the base struct's 
        public and protected members as public and protected, respectively. 
        In the case of a class, the default inheritance access specifier is private, 
        so the derived class inherits the base class's public and protected members as private.

        4. Historical Difference: Historically, in C, structs were used to represent data structures, 
        while classes were introduced in C++ to support object-oriented programming paradigms. 
        However, with the addition of features like constructors, destructors, 
        and member functions to structs in C++, the distinction between structs and classes has become less significant,
        and the choice between them often depends on the intended usage and programming style.

        It's worth noting that the differences between classes and structs have become less significant in modern C++. 
        Both classes and structs can have constructors, destructors, member functions, and access specifiers. 
        The decision between using classes or structures often comes down to personal or team coding conventions, 
        design preferences, and the intended semantics of the data type.

        You can achieve nearly everything that is achievable with classes using structures as well!
    */
}
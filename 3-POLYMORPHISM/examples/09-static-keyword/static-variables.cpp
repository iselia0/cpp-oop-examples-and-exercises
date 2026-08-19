#include <iostream>

using namespace std;

/*
    Polymorphism

    9. Static Keyword in C++
*/


/*
    In C++, a static variable is a variable that has a specific storage duration and scope, 
    and it retains its value across function calls and even when the scope that defines it is exited. 
    Static variables are declared using the static keyword.
    
    Following are some interesting facts about static variables:

    1. A static int variable remains in memory while the program is running. 
    A normal or auto variable is destroyed when a function call where the variable was declared is over. 
    2. Static variables are allocated memory in the "Data" segment, not the "Stack" segment.
    3. Static variables (like global variables) are initialized as 0 if not initialized explicitly. 
*/


/*
    There are two main types of static variables in C++:

    1. Static Local Variables:
        ~ Static local variables are declared inside a function or a block and are prefixed with the static keyword.
        ~ They are initialized only once, the first time the function is called, and they retain their value between subsequent calls.
        ~ Static local variables have local scope, meaning they are only accessible within the function or block in which they are defined.
*/

// Example of a static local variable:
void foo() {
    static int count = 0;   // Static local variable
    count++;
    cout << "Count: " << count << endl;
}


/*
    2. Static Class Member Variables:
        ~ Static member variables are declared inside a class and are prefixed with the static keyword.
        ~ They are associated with the class itself rather than with instances of the class.
        ~ Static member variables are shared among all instances of the class.
        ~ They are typically used for class-level data that should not be duplicated for each instance.
*/

// Example of a static class member variable:
class MyClass {
    public:
        static int count;   // Static class member variable
        
        MyClass() {
            count++;
        }
};

int MyClass::count = 0;   // Initialize the static member variable


int main() {

    system("clear");

    foo();   // Count: 1
    foo();   // Count: 2
    foo();   // Count: 3  

    cout << "-------" << endl; 


    MyClass obj1;
    MyClass obj2;
    // Recall that: ~ They are associated with the class itself rather than with instances of the class

    cout << "Count: " << MyClass::count << endl;    // // Count: 2

}
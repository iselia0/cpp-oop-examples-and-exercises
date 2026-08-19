#include <iostream>
#include <math.h>

using namespace std;

/*
    8. Destructors

    Destructor is a special member function of a class that is automatically called 
    when an object of that class is destroyed or goes out of scope.

    Destructor is responsible for releasing any resources allocated by the object during its lifetime.
    It will be very useful if we allocate dynamic memory in the constructor.
    Destructors are useful for releasing resources before exiting a program, 
    such as closing files and releasing memories.
    They can also be used to clean up any data that was allocated by the object.
                            
    The syntax for a destructor is similar to that of a constructor but with a tilde (~) followed by the class name.
*/


// Here's an example of a destructor:
class MyClass {
    public:
        // Constructor
        MyClass() {
            // Constructor code
        }

        // Destructor
        ~MyClass() {
            // Destructor code
        }
};


/*
    Some key points about destructors in C++:

    1. Destructors have no return type and no parameters.
    2. There can only be one destructor in a class, and it cannot be overloaded with different parameters.
    3. Destructors are automatically called by the compiler when an object of the class goes "out of scope", 
    is explicitly deleted using the delete keyword, or when the program terminates.
    4. Destructors are useful for releasing resources such as dynamic memory, file handles, network connections, etc.
    5. If a class doesn't have a defined destructor, the compiler generates a default destructor that does nothing.
*/


// Example demonstrating the usage of a destructor to release dynamically allocated memory:
class DynamicArray {
    private:
        int *data;

    public:
        DynamicArray(int size) {
            data = new int[size];
        }

        ~DynamicArray() {
            delete []data;
            data = nullptr;
            cout << "Memory freed!" << endl;
        }    
};
/*
    In this example, the destructor of the DynamicArray class is responsible 
    for releasing the memory allocated using the new operator in the constructor. 
    This ensures that the memory is properly deallocated when the object is destroyed.
*/



class Dog {
    public : 
        Dog() = default;
        Dog(string name_param, string breed_param, int age_param);
        ~Dog();

    private : 
        string name;
        string breed;
        int *p_age;
};

Dog::Dog(string name_param, string breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    cout << "Dog constructor called for " << name << endl;
}

Dog::~Dog() {
    delete p_age;
    cout << "Dog destructor called for : " << name << endl;
}


void some_func() {
    Dog *p_dog = new Dog("Fluffy", "Shepherd", 2);

    delete p_dog;   // Causes for the destructor of Dog to be called
}

void dogRex() {
    Dog *rex = new Dog("Rex", "Shepherd", 1);
}
/*
    Where and how do we cause memory leak?
*/



int main() {
    DynamicArray array1(10);
    // Do something with the array

    {
        DynamicArray array2(15);
    } 
    // When array goes out of scope


    some_func();
    cout << "Done!" << endl << endl;

    dogRex();

    // When array goes out of scope or is explicitly deleted, the destructor is automatically called
    return 0;
}
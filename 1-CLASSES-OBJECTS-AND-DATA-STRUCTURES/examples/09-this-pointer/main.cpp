#include <iostream>

using namespace std;


/*
    10. The "this" Pointer

    Each class member function contains a hidden pointer called "this".
    That pointer contains the address of the current object, for which the method is being executed.
    "This" also applies to constructors and destructors.
*/


// Example 1:
class MyClass { 
    int value;

    public:
        void setValue(int value) {
           this->value = value;    // Accessing member variable using 'this'
        }

        void printValue() {
            cout << "Value: " << this->value << endl;   // Accessing member variable using 'this'
        }

        // Usage of the "this" pointer in constructors and destructors:
        MyClass() = default;

        MyClass(int value) {
            this->value = value;    // Accessing member variable using 'this'
            cout << "Constructor called. Value set to: " << this->value << endl;
        }

        ~MyClass() {
            cout << "Destructor called. Value: " << this->value << endl;
        }
};



// Exexample 2:
class Dog {
    public : 
        Dog() = default;
        Dog(string name_param, string breed_param, int age_param);
        ~Dog();

        void print_info() const {
            cout << "Dog (" << this << ") : [ name: " << name << ", breed: " << breed << ", age:" << *p_age << " ]" << endl;
        }

        // Setters
        void set_dog_name(string name) {
            // without "this" pointer it will look like:
            // name = name;
            this->name = name;
        }

        void set_dog_breed(string breed) {
            this->breed = breed;
        }

        void set_dog_age(int age) {
            *(this->p_age) = age;   // Why not [this->p_age = age]?
        }

    private: 
        string name;
        string breed;
        int *p_age = nullptr;
};

Dog::Dog(string name_param, string breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    cout << "Dog constructor called for " << name << " at: " << this << endl;
}

Dog::~Dog() {
    delete p_age;
    cout << "Dog destructor called for " << name << " at: " << this << endl;
}




// Exexample 3:
class Cat {
    public:
        Cat() = default;
        Cat(string name_param, string breed_param, int age_param);
        ~Cat();

        void print_info() const {
            cout << "Cat (" << this << ") : [ name: " << name << ", breed: " << breed << ", age:" << *p_age << " ]" << endl;
        }

        // Setters

        // Chained calls using Pointers
        Cat *set_cat_name(string name) {
            this->name = name;
            return this;
        }

        Cat * set_cat_breed(string breed) {
            this->breed = breed;
            return this;
        }

        Cat* set_cat_age(int age) {
            *(this->p_age) = age; 
            return this;
        }


        // Chained calls using References
        Cat &ref_set_cat_name(string name) {
            this->name = name;
            return *this;
        }

        Cat & ref_set_cat_breed(string breed) {
            this->breed = breed;
            return *this;
        }
        
        Cat& ref_set_cat_age(int age) {
            *(this->p_age) = age; 
            return *this;
        }

    private:
        string name;
        string breed;
        int *p_age = nullptr;
};

Cat::Cat(string name_param, string breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    cout << "Cat constructor called for " << name << " at: " << this << endl;
}

Cat::~Cat() {
    delete p_age;
    cout << "Cat destructor called for " << name << " at: " << this << endl;
}



int main() {

    // Exexample 1:
    MyClass obj1;
    obj1.setValue(42);
    obj1.printValue(); // Output: Value: 42

    MyClass obj2;
    obj2.setValue(99);
    obj2.printValue(); // Output: Value: 99
    
    cout << endl;

    MyClass obj3(10); // Constructor called. Value set to: 10

    {
        MyClass obj4(25);   // Constructor called. Value set to: 25
    } // Destructor called. Value: 25

    // Destructor of obj3 will be called at the end of the scope
    // Destructor called. Value: 10
    cout << endl << endl;


    
    // Exexample 2:
    Dog dog1("Fluffy", "Shepherd", 2);

    dog1.print_info();

    dog1.set_dog_name("Bim");
    dog1.set_dog_breed("Wire Fox Terrier");
    dog1.set_dog_age(4);

    dog1.print_info();

    cout << endl << endl;



    /*
        [Some Recap]:
        
        Cat cat2("Charlie", "Siamese cat", 1);
        Cat *pCat = &cat2;

        (*pCat).print_info();
        pCat->print_info();

        cout << endl;


        Cat cat3("Leo", "Munchkin cat", 4);
        Cat &refCat = cat3;

        refCat.print_info();
        cout << endl;
    */
    

    
    // Example 3:
    Cat cat1("Bob", "Scottish Fold", 2);

    cat1.print_info();

    cat1.set_cat_name("Garfield")->set_cat_breed("Unspecified")->set_cat_age(3);    // chained calls using pointers

    cat1.print_info();

    cout << endl;


    cat1.ref_set_cat_name("Charlie").ref_set_cat_breed("Siamese").ref_set_cat_age(8);   // chained calls using references
    cat1.print_info();

    cout << endl << endl;


    

    return 0;
}


/*
    Some common use cases for the "this" pointer:
*/

/*
    1. Differentiating between Local and Member Variables.
*/
class A {
    public:
        void setValue(int value) {
            this->value = value;   // 'this' pointer disambiguates the member variable
        }

    private:
        int value;
};


/*
    2. Returning the Current Object: 

    The this pointer can be used to return the current object from a member function, enabling method chaining. 
    This allows for a more fluent and concise style of programming.
*/
class B {
    public:
        B *setName(const string& name) {
            this->name = name;
            return this;    // Returning the memeory address of current object
        }

        B &setAge(int age) {
            this->age = age;
            return *this;   // Returning the current object itself
        }

    private:
        string name;
        int age;
};


/*
    3. Accessing Other Members: 

    The this pointer can be used to access other members of the current object within a member function. 
    It allows you to read or modify other members of the object easily.
*/
class C {
    public:
        void setCoordinates(const int &x, const int &y) {
            this->x = x;
            this->y = y;
        }

        void printCoordinates() const {
            cout << "X: " << this->x << ", Y: " << this->y << endl;
        }

    private:
        int x;
        int y;
};


/*
    4. Passing the Current Object as a Parameter: 

    In certain cases, you may need to pass the current object as a parameter to another function.
    By passing this as an argument, you allow the other function to operate on the current object.
*/
class D {
    public:
        void doSomething() {
            helperFunction(this);   // Passing the current object as a parameter
        }

        void helperFunction(D *obj) {
            // Perform operations on the passed object
        }
};

/*
    Briefly, it allows you to 1) differentiate between local and member variables, 
    2) return the current object, 3) access other members easily, 
    and 4) pass the current object as a parameter to other functions.
*/
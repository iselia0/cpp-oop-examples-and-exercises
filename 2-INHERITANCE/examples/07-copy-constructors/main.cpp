#include <istream>

#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

using namespace std;

/*
    Inheritance

    8. Copy Constructors with Inheritance
*/

/*
    In C++, a copy constructor is a special constructor that initializes 
    a new object using an existing object of the same class. 
    When it comes to inheritance, copy constructors can play an important role 
    in ensuring that the base class and derived class objects are copied correctly. 
*/

class Base {
    public:
        Base(int value) : data(value) {}
        Base(const Base &other) : data(other.data) {}

        int getData() const { return data; }

    private:
        int data;
};

class Derived : public Base {
    public:
        Derived(int value, double factor) : Base(value), factor(factor) {}
        
        Derived(const Derived &other) : Base(other), factor(other.factor) {
            cout << "Copy Constructor Called For Derived..." << endl;
        }

        double getFactor() const { return factor; }

    private:
        double factor;
};


int main() {

    system("clear");

    Derived original(10, 2.5);
    Derived copy = original;  // Invokes the copy constructor
    cout << endl;
    

    Engineer engineer_1("Daniel Gray", 41, "Green Sky Oh Blue", 12);
    cout << "---------" << endl;
    
    /* 
        The "default copy constructor" will be called by the system
        if we don't have our "own copy constructor"
    */
    Engineer engineer_2(engineer_1);
    cout << "engineer_2: " << engineer_2 << endl;
    cout << endl << "---------" << endl;


    CivilEngineer civil_engineer_1("Daniel Gray", 41, "Green Sky Oh Blue", 12, "Road Strength");
    cout << "---------" << endl;

    CivilEngineer civil_engineer_2 = civil_engineer_1;
    cout << "civil_engineer_2: " << civil_engineer_2 << endl;

}
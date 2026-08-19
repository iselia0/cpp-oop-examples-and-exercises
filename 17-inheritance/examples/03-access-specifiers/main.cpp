#include <istream>

#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

using namespace std;

/*
    Inheritance

    4. Base class access specifiers : Zooming in
*/


/*
    Definition:

    In object-oriented programming, class access specifiers determine the visibility 
    and accessibility of class members (attributes and methods) from outside the class. 
    
    The three primary access specifiers in most programming languages are:
        1. Public: Members declared as public are accessible from anywhere, 
        both within the class and outside the class. 
        They can be accessed by any code that has access to the object of that class.

        2. Protected: Members declared as protected are accessible within the class itself and its subclasses (derived classes). 
        Outside the class hierarchy, these members are not directly accessible.

        3. Private: Members declared as private are accessible only within the class where they are defined. 
        They are not accessible from outside the class, not even from subclasses.


    In C++, inheritance comes in three flavors: public, protected, and private inheritance. 
    Each type specifies the visibility of the base class members in the derived class. 
    Let's take a closer look at each:
*/


class Base {
    private:
        int age;

    protected:
        int id;

    public:
        int publicMember;
};


/*
    1. Public Inheritance:
        In public inheritance, the public members of the base class become public members of the derived class.
        Protected members of the base class become protected members of the derived class.
        Private members of the base class remain inaccessible to the derived class.
        This type of inheritance represents an "is-a" relationship. 
        It means that the derived class is a type of the base class and can be used interchangeably with objects of the base class.
*/
class Derived_1 : public Base {
    // publicMember from Base is accessible as public in Derived
    /*
        Base:: ...
    */
};


/*
    2. Protected Inheritance:
        In protected inheritance, the public and protected members of the base class 
        become protected members of the derived class.
        Private members of the base class remain inaccessible to the derived class.
        This type of inheritance is less common and is used to establish a "derived-from-implemented" relationship, 
        where the derived class wants to use the implementation details of the base class without exposing them to the outside world.
*/
class Derived_2 : protected Base {
    // publicMember from Base is accessible as protected in Derived
};


/*
    Private Inheritance:
    In private inheritance, both the public and protected members of the base class become private members of the derived class.
    Private members of the base class remain inaccessible to the derived class.
    This type of inheritance establishes an "implemented-in-terms-of" relationship, where the derived class 
    wants to reuse the implementation of the base class but does not want to be treated as a type of the base class.
*/
class Derived_3 : private Base {
    public:
        int x = Base::publicMember;
    // publicMember from Base is accessible as private in Derived
};




int main() {

    system("clear");


    Person person1("Edward Norton", 32, "Pennsylvania");
    cout << person1 << endl;


    Player player;
    player.m_full_name = "Samuel jackson";
    //  player.m_age = 55;          [Compile Error]
    //  player.m_address = "Uwork";  [Compile Error]


    Nurse nurse1;
    // nurse1.m_age = 51;   [Compile Error]
    // nurse1.m_full_name = "Davy Johnes";   [Compile Error]


    Engineer engineer1;
    // engineer1.m_age = 23;     [Compile Error]
    // engineer1.m_address = "4a_D";     [Compile Error]
    // engineer1.m_full_name = "Oliver Stone";     [Compile Error]
}



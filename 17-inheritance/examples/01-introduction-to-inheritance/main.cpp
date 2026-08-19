#include <istream>
#include <ostream>
#include "player.h"

using namespace std;

/*
    Inheritance

    1. Introduction to Inheritance
    2. First try on Inheritance
    3. Protected members
    4. Base class access specifiers : Zooming in
    5. Closing in on Private Inheritance
    6. Default Constructors with Inheritance
    7. Custom Constructors With Inheritance
    8. Copy Constructors with Inheritance
    9. Inheritance and Destructors
    10. Reused Symbols in Inheritance
*/


/*
    Definition:

    Inheritance is a fundamental concept in object-oriented programming (OOP) 
    that allows you to create a new class (subclass or derived class) 
    based on an existing class (superclass or base class).
*/


int main() {

    system("clear");

    /*
        Without string_view we could not send string value itself because:

        Assume:
            Player(string &game_param);

        then in here we have to pass game name like this:
            string game = "Basketball";
            Player p1(game);  
    */

    Player p1("Basketball");

    p1.set_first_name("Oliver");
    p1.set_last_name("Stone");

    cout << p1 << endl;   // Player: [ game: Basketball, names: Oliver Stone ]

}


/*
    Benefits

    1. Building types on top of other types
    2. Inheritance hierarchies can be customized to suit your needs.
    3. Code reuse improved
    4. Encapsulation and Information Hiding
        Inheritance supports encapsulation by allowing you to define private or protected members 
        in the superclass that are hidden from external classes but accessible to subclasses. 
        This helps manage the visibility of certain attributes or methods.
    5. Modeling Real-World Relationships
        Ex: For instance, a "Vehicle" superclass with subclasses like "Car," "Truck," and "Motorcycle" 
        closely mirrors the hierarchy found in the real world. 
*/
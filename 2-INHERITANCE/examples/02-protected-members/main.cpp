#include <istream>

#include "player.h"

using namespace std;

/*
    Inheritance

    3. Protected members
*/

/*
    We will introduce a new access specifier so called "protected"

    In the previous lecture, we saw that private member variables will not be accessed 
    or used from derived classes using public inheritance.

    Sometimes we want the members of the base class to be at least accessible and usable from within the derived class, 
    but still not accessible from the outside.

    And we can achieve this by using "protected" access specifier.
    And the moment we do that, we can read or change those member variables from the derived classes.
    However, we won't be able to use these member variables outside of derived classes.
*/


int main() {

    system("clear");

    Player p1("Basketball", "John", "Snow");

    /*
        Compile Time Error:

        p1.first_name = "Oliver";
        p1.last_name  = "Stone";

        Why? Because protected members are not accessible from the outside.
    */
    
    cout << p1 << endl;   // Player: [ game: Basketball, names: John Snow ]

}
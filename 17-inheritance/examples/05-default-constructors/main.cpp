#include <istream>
#include <string_view>

#include "person.h"
#include "engineer.h"
#include "civilengineer.h"


using namespace std;

/*
    Inheritance

    6. Default Constructors with Inheritance
*/


/*
    Always provide a default constructor for your class, 
    especially if they will be part of an inheritance hierarchy.
    But why?
*/


int main() {

    system("clear");

    CivilEngineer ce_1;

    /*
        [Output]

        Default constructor for Person called...
        Default constructor for Engineer called...
        Default constructor for CivilEngineer called...
    */

    cout << endl;

}
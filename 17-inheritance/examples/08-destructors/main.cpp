#include <istream>

#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

using namespace std;

/*
    Inheritance

    9. Inheritance and Destructors
*/




int main() {

    system("clear");

    CivilEngineer civil_engineer_1("Daniel Gray", 41, "Green Sky Oh Blue", 12, "Road Strength");
    cout << endl;

    /*
        [Output]

        Constructor for Person called...
        Constructor for Engineer called...
        Constructor for CivilEngineer called...

        CivilEngineer Destructor is called...
        Engineer Destructor is called...
        Person Destructor is called...
    */

    /* ----- Why are Constructors and Destructors (reverse order) called in that order? ----- */
}
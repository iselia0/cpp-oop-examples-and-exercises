#include <istream>

#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

using namespace std;

/*
    Inheritance

    7. Custom Constructors With Inheritance
*/



int main() {

    system("clear");

    Person person1("John Snow", 27, "Winterfall Cold#33S");
    cout << "person1: " << person1 << endl << endl;


    Engineer engineer1("Daniel Gray", 41, "Green Sky On Blue 33St#75", 12);
    cout << "engineer1: " << engineer1 << endl << endl;


    CivilEngineer civilengineer1("John Travolta", 51, "Tiny Dog 42St#89", 31, "Road Strentgth");
    cout << "civilengineer1: " << civilengineer1 << endl << endl;

}
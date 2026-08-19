#include <iostream>
#include "cylinder.h"

using namespace std;


int main() {

    system("clear");

    Cylinder cylender1;

    cout << "volume 1: " << cylender1.volume() << endl;

    // Overloads constructor by taking parameters
    Cylinder cylender2(12, 13);

    cout << "volume 2: " << cylender2.volume() << endl;

}




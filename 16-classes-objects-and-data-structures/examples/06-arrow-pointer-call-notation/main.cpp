#include <iostream>
#include "cylinder.h"

using namespace std;


/*  7. Arrow pointer call notation  */


int main() {

    // Stack object; "." - notation
    Cylinder c1(10, 2);
    cout << "volume c1 = " << c1.volume() << endl;

    // Heap object
    Cylinder *c2 = new Cylinder(11, 20);    // create object on the heap

    // (*objectPointer).property() is equivalent to objectPointer->property()
    cout << "volume c2 = " << (*c2).volume() << endl;
    cout << "volume c2 = " << c2->volume() << endl;

    cout << endl;

    delete c2;   // remember to release memory from heap


    // managing stack object through pointers
    Cylinder cylinder(10, 10);
    Cylinder *pCylinder = &cylinder;    

    cout << "&cylender: " << &cylinder << endl;
    cout << "sizeof(cylender): " << sizeof(cylinder) << endl;

    cout << "pCylinder:  " << pCylinder << endl;
    cout << "&pCylinder: " << &pCylinder << endl;

    cout << "volume: " << (*pCylinder).volume() << endl;
    cout << "volume: " << pCylinder->volume() << endl << endl;



    // Сreate a cylinder object in the heap memory through new operator
    Cylinder *pCylinder_2 = new Cylinder(2, 100);   // HEAP

    cout << "volume: " << pCylinder_2->volume() << endl;
    cout << "radius: " << pCylinder_2->get_base_radius() << endl;

    cout << endl << endl;
    cout << "pCylinder_2: " << pCylinder_2 << endl;

    delete pCylinder_2;   // release heap memory
    //pCylinder_2 = nullptr;
    
    cout << "pCylinder_2: " << pCylinder_2->volume() << endl;

}


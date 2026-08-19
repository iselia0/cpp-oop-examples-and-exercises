#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

// Preview of a class
class Cylinder {
    public : 
        // Constctors
        Cylinder() {}
        Cylinder(double rad_param, double height_param);

        // Functions (methods)
        double volume();
        
        // Setter and getter methods
        double get_base_radius();
        double get_height();

        void set_base_radius(double rad_param);
        void set_height(double height_param);

    private : 
        // Member variables
        double base_radius;
        double height;
};


// Implementation also possible here
Cylinder::Cylinder(double rad_param, double height_param) {
    base_radius = rad_param;
    height = height_param;
}

double Cylinder::volume() {
    return PI * base_radius * base_radius * height;  // PI? but it works
}

// Setter and getter methods
double Cylinder::get_base_radius() {
    return base_radius;
}
double Cylinder::get_height() {
    return height;
}

void Cylinder::set_base_radius(double rad_param) {
    base_radius = rad_param;
}

void Cylinder::set_height(double height_param) {
    height = height_param;
}


#endif
#include <iostream>
#include <string>

using namespace std;


/*
    9. Order of Constructor Destructor Calls
*/


class Dog {
    public : 
        Dog() = default;
        Dog(string name_param, string breed_param, int age_param);
        ~Dog();

    private : 
        string name;
        string breed;
        int p_age;
};

Dog::Dog(string name_param, string breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = age_param;
    cout << "Dog constructor called for " << name << endl;
}

Dog::~Dog() {
    cout << "Dog destructor called for : " << name << endl;
}


int main() {

    system("clear");

    Dog dog1("Doggy1", "Shepherd", 1);
    Dog dog2("Doggy2", "Shepherd", 2);
    Dog dog3("Doggy3", "Shepherd", 3);
    Dog dog4("Doggy4", "Shepherd", 4);

    cout << "-------" << endl;

    /*
        Output:

        Dog constructor called for Doggy1
        Dog constructor called for Doggy2
        Dog constructor called for Doggy3
        Dog constructor called for Doggy4
        -------
        Dog destructor called for : Doggy4
        Dog destructor called for : Doggy3
        Dog destructor called for : Doggy2
        Dog destructor called for : Doggy1
    */

    /*
        Why order of constructor destructor calls in C++ follows in this manner?

        Answer: 
        By following this order of constructor and destructor calls, 
        C++ ensures that objects and their components are initialized and cleaned up in a predictable and orderly manner, 
        considering the dependencies and relationships within the class hierarchy. 
        This helps prevent issues such as using uninitialized objects or accessing destroyed resources.
    */

}
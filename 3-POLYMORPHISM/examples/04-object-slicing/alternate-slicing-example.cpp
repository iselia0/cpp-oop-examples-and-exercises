#include <iostream>
#include <string>

using namespace std;

/*

    The concept of inheritance slicing in C++ do not have direct practical use cases, 
    as it's more of a situation to be aware of and avoid. 
    However, understanding slicing is important in the context of polymorphism and object-oriented programming. 

    Here is one example:
*/
class Animal {
    public:
        Animal(const string& name) : name(name) {}

        void makeSound() const {
            cout << "Generic animal sound\n";
        }

        void printName() const {
            cout << "Name: " << name << "\n";
        }

    private:
        string name;
};


class Dog : public Animal {
    public:
        Dog(const string& name, const string& breed) : Animal(name), breed(breed) {}

        void makeSound() const {
            cout << "Woof! Woof!\n";
        }

        void printBreed() const {
            cout << "Breed: " << breed << "\n";
        }

    private:
        string breed;
};


int main() {

    Dog myDog("Buddy", "Golden Retriever");

    // Implicit conversion and slicing
    Animal slicedAnimal = myDog;

    slicedAnimal.makeSound();
    slicedAnimal.printName();

}
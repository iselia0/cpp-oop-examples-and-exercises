#include <iostream>

using namespace std;

/*
    Polymorphism

    11. Inheritance and Polymorphism at different levels
*/


/*
                                Animal(breathes)

              Domestic(runs)                        Bird(flies)

        Dog(barks)     Cat(miaw)            Pigeon(coos)     Crow(caws)
*/

class Animal {
    public:
        Animal(string_view description_param) : description(description_param) {}
        
        virtual ~Animal() {}

        virtual void breathe() const {
            cout << description << " is breathing" << endl;
        }
    
    protected:
        string description;
};


class Domestic : public Animal {
    public:
        Domestic(string_view fur_style_p, string_view description_p) : Animal(description_p), fur_style(fur_style_p) {}

        virtual ~Domestic() {}

        /* 
            There is no need to mention the override keyword 
            since we are not going to create an object for the Domestic class.
        */
        virtual void run() const {
            cout << "Domestic " << description << " is running" << endl;
        }

    public:
        string fur_style;
};


class Dog : public Domestic {
    public:
        Dog(string_view fur_style, string_view description) : Domestic(fur_style, description) {}

        virtual ~Dog() {}

        void bark() const {
            cout << "Dog::bark() called : woof!" << endl;
        }

        virtual void breathe() const override {
            cout << "Dog::breathe() called for dog: " << description << endl;
        }

        virtual void run() const override {
            cout << "Dog " << description << " is running" << endl;
        }
};


class Cat : public Domestic {
    public:
        Cat(string_view fur_style, string_view description) : Domestic(fur_style, description) {}

        virtual ~Cat() {}

        void miaw() const {
            cout << "Cat::miaw() called for cat!" << endl;
        } 

        virtual void breathe() const override {
            cout << "Cat::breathe() called for cat: " << description << endl;
        }

        virtual void run() const override {
            cout << "Cat " << description << " is running" << endl;
        }
};


class Bird : public Animal {
    public:
        Bird(string_view wing_color_p, string_view description) : Animal(description), wing_color(wing_color_p) {}

        ~Bird() {}

        virtual void fly() const {
            cout << "Bird::fly() called for bird!" << endl;
        }  

    private:
        string wing_color;
};


class Pigeon : public Bird {
    public:
        Pigeon(string_view wing_color_p, string_view description) : Bird(wing_color_p, description) {}

        ~Pigeon() {}

        void coo() const {
            cout << "Pigeon::coo() called for Pigeon!" << endl;
        }

        virtual void fly() const override {
            cout << description << "::fly() called for pigeon!" << endl;
        } 

        virtual void breathe() const override {
            cout << "Pigeon::breathe() called for pigeon: " << description << endl;
        }
};

class Crow : public Bird {
    public:
        Crow(string_view wing_color_p, string_view description) : Bird(wing_color_p, description) {}

        ~Crow() {}

        void joke() const {
            cout << "Crow::joke() called for Crow!" << endl;
        }

        virtual void fly() const override {
            cout << description << "::fly() called for crow!" << endl;
        }  

        virtual void breathe() const override {
            cout << "Crow::breathe() called for crow: " << description << endl;
        }
};



int main() {

    system("clear");

    Dog dog_1("gray", "dog-1");
    Cat cat_1("black", "cat-1");
    Pigeon pigeon_1("white", "pigeon-1");
    Crow crow_1("brown", "crow-1");

    Animal *animals[] = {&dog_1, &cat_1, &pigeon_1, &crow_1};

    for (const auto& animal: animals) {
        animal->breathe();
    }
    /*
        [Output]

        Dog::breathe() called for dog: dog-1
        Cat::breathe() called for cat: cat-1
        Pigeon::breathe() called for pigeon: pigeon-1
        Crow::breathe() called for crow: crow-1
    */
    cout << "---------" << endl;


    Dog dog_2("gray", "dog-2");
    Cat cat_2("black", "cat-2");

    Pigeon pigeon_2("pink", "pigeon-2");    // Putting pigeon in Domestic will result compile time error. Why?
    Animal some_animal("some-animal");      // Putting Animal in Domestic will result compile time error. Why?

    Domestic *domestic[] = {&dog_2, &cat_2};

    for (const auto& animal : domestic) {
        animal->run();
    }
    /*
        [Output without "run" overriden methods in Dog and Cat classes]
          Domestic dog-2 is running
          Domestic cat-2 is running

        [Output with "run" overriden methods in Dog and Cat classes]
          Dog dog-2 is running
          Cat cat-2 is running
    */
    cout << "---------" << endl;


    // Bird polymorphism
    Pigeon pigeon_3("white", "pigeon-3");
    Crow crow_3("brown", "crow-3");

    Bird *birds[] = {&pigeon_3, &crow_3};

    for (auto const& bird : birds) {
        bird->fly();
    }
    /*
        [Output]
        
        pigeon-3::fly() called for pigeon!
        crow-3::fly() called for crow!
    */
    cout << "---------" << endl;
    

    for (auto const& bird : birds) {
        bird->breathe();
    }
    /*
        [Output]
        
        Pigeon::breathe() called for pigeon: pigeon-3
        Crow::breathe() called for crow: crow-3 
    */


    /* 
        The main message is that you can set up polymorphism at different levels in your inheritance hiearachy!
    */
}
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person {
    friend ostream& operator << (ostream &out, const Person &person);

    public:
        Person();
        Person(string &fisrt_name_param, string &last_name_param);

        // Getters
        string get_first_name() const {
            return first_name;
        }

        string get_last_name() const {
            return last_name;
        }

        // Setters
        void set_first_name(string_view fn) {
            this->first_name = fn;
        }

        void set_last_name(string_view ln) {
            this->last_name = ln;
        }

    protected:
        string first_name;
        string last_name;
        
    private:
        string id;
};

ostream& operator << (ostream &out, const Person &person) {
    out << "Person [" << person.first_name << " " << person.last_name << "]";
    return out;
}

Person::Person() 
{

}

Person::Person(string &first_name_param, string &last_name_param) : 
        first_name(first_name_param), 
        last_name(last_name_param)
{

}


#endif
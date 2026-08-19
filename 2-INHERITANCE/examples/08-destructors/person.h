#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person {

    friend ostream& operator << (ostream& , const Person& person);

    public:
        Person();
        Person(string_view fullname, int age, string_view address);

        // For copy constructor
        Person(const Person &source);

        ~Person();
        
        //Getters
        string get_full_name()const{
            return m_full_name;
        }
        
        int get_age()const{
            return m_age;
        }
        
        string get_address() const {
            return m_address;
        }

    public:
        string m_full_name;

    protected: 
        int m_age;

    private : 
        string m_address;
};


Person::Person() 
{
    m_age = 0;
    m_full_name = m_address = "None";
}


Person::~Person()
{
    cout << "Person Destructor is called..." << endl;
}


/*
    This is all we need to do in order to set copy constructor.
*/
Person::Person(const Person &source) 
        : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address)
{
    cout << "Person Copy Constructor called..." << endl;
}


Person::Person(string_view fullname, int age, string_view address) 
        : m_full_name(fullname), m_age(age), m_address(address)
{
    cout << "Constructor for Person called..." << endl;
}

ostream& operator<<(ostream& out , const Person& person) {
   out << "Person [Full name: " << person.get_full_name() <<
                      ", Age: " << person.get_age() <<
                      ", Address: " << person.get_address() << "]";
  return out;
}


#endif // PERSON_H
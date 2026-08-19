#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"

class CivilEngineer : public Engineer {

    friend ostream& operator << (ostream&, const CivilEngineer& operand);

    public:
        CivilEngineer();
        CivilEngineer(string_view fullname, int age, string_view address, int contract_count, string_view speciality);

        // Copy constructor
        CivilEngineer(const CivilEngineer &source);

        ~CivilEngineer();
    
    void build_road(){
        
    }
	
    private: 
        string m_speciality;

};


CivilEngineer::CivilEngineer()
{
    m_speciality = "None";
}

CivilEngineer::~CivilEngineer()
{
    cout << "CivilEngineer Destructor is called..." << endl;
}

// This copy constructor will not create the copy object for Engineer class.
CivilEngineer::CivilEngineer(const CivilEngineer &source) : Engineer(source), m_speciality(source.m_speciality)
{
    cout << "CivilEngineer Copy Constructor called..." << endl;
}

CivilEngineer::CivilEngineer(string_view fullname, int age, string_view address, int contract_count, string_view speciality) 
              : Engineer(fullname, age, address, contract_count), m_speciality(speciality)
{
    cout << "cConstructor for CivilEngineer called..." << endl;

    /* ------------------------------ Bad Practice!!! ------------------------------ */
    m_full_name = fullname;
    m_age = age;
    /*
        m_address = address;    
        [Compile Error]: member "Person::m_address" is inaccessible

        Even with this method, we cannot access m_address. 
        However, we can initialize its private members using a call to the Engineer constructor.

        It's best to call the base constructor, 
        as this action delegates the responsibility of initializing the variables to the base class.

        In addition, in cases of private inheritance and the use of a base class constructor, 
        we can conveniently initialize members that are specific to the derived class.
    */
    m_speciality = speciality;
}


ostream& operator << (ostream& out, const CivilEngineer& operand) {
     out << "CivilEngineer [Full name: " << operand.get_full_name() <<
                    ", age: " << operand.get_age() << 
                    ", address: " << operand.get_address() <<
                    ", contract_count: " << operand.get_contract_count() <<
                    ", speciality: " << operand.m_speciality << "]";
                    		
    return out; 
}

#endif // CIVIL_ENGINEER_H
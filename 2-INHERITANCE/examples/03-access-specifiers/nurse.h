#ifndef NURSE_H
#define NURSE_H

#include "person.h"


class Nurse : protected Person {    // Nurse will do protected inheritance

	friend ostream& operator << (ostream&, const Nurse& operand);

    public:
        Nurse();
        ~Nurse();
        
        void treat_unwell_person(){
            m_full_name = "John Snow";  // OK
            m_age = 23;   // OK
            //  m_address = "897-78-723";   [Compiler error]
        }
        
    private : 
        int practice_certificate_id;
};


Nurse::Nurse()
{
    practice_certificate_id = 0;
}

ostream& operator<<(ostream& out , const Nurse& operand){
    out << "Nurse [Full name: " << operand.get_full_name() <<
                    ", age: " << operand.get_age() << 
                    ", address: " << operand.get_address() <<
                    ", practice certificate id: " << operand.practice_certificate_id << "]";
    return out;
}


Nurse::~Nurse()
{
}

#endif // NURSE_H
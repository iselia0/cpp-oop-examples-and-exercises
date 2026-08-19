#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"

// Engineer is doing private inheritance
class Engineer : private Person {

    friend ostream& operator << (ostream& out, const Engineer& operand);

    public:
        Engineer();
        ~Engineer();
        
        void build_something() {
            m_full_name = "John Snow"; // OK
            m_age = 23; // OK
            // m_address = "897-78-723"; [Compiler error]
        }
        
    private: 
        int contract_count;
};


Engineer::Engineer()
{
    contract_count = 0;
}

ostream& operator << (ostream& out , const Engineer& operand){
     out << "Engineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count << "]";
    return out;   
}


Engineer::~Engineer()
{
}

#endif // ENGINEER_H
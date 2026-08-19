#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"

class CivilEngineer : public Engineer {

    friend ostream& operator << (ostream&, const CivilEngineer& operand);

    public:
        CivilEngineer();
        ~CivilEngineer();
    
    void build_road(){
        // get_full_name();                [Compiler error]
        // m_full_name = "Daniel Gray";    [Compiler error]
        // m_age = 45;                     [Compiler error]
    }
	
    private: 
        string m_speciality;

};


CivilEngineer::CivilEngineer()
{
    m_speciality = "None";
}

ostream& operator << (ostream& out, const CivilEngineer& operand) {
    
    /*
        Because of private inheritance "class Engineer : private Person"
        we can not access all the public methods or members from the CivilEngineer class.
    */ 

    /*
     out << "CivilEngineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    //",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count << "]";
                    */
                  
				
    return out;  
}


CivilEngineer::~CivilEngineer()
{
}

#endif // CIVIL_ENGINEER_H
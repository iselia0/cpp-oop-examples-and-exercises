#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"

class CivilEngineer : public Engineer {

    friend ostream& operator << (ostream&, const CivilEngineer& operand);

    public:
        CivilEngineer();
        ~CivilEngineer();
    
    void build_road() {
        get_full_name();              
        m_full_name = "Daniel Gray";    
    }
	
    private: 
        string m_speciality;
};


CivilEngineer::CivilEngineer()
{
    m_speciality = "None";
    cout << "Default constructor for CivilEngineer called..." << endl;
}

ostream& operator << (ostream& out, const CivilEngineer& operand) {

    /*
     out << "CivilEngineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    //",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count <<
                    ",speciality : " << operand.m_speciality << "]";
                    */
                  
				
    return out;  
}


CivilEngineer::~CivilEngineer()
{
}

#endif // CIVIL_ENGINEER_H
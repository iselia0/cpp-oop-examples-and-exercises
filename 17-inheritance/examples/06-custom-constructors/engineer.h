#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"

// Engineer is doing public inheritance
class Engineer : public Person {

    friend ostream& operator << (ostream& out , const Engineer& operand);

    public:
        Engineer();
        Engineer(string_view fullname, int age, string_view address, int contract_count_param);
        ~Engineer();
        
        void build_something() {
            m_full_name = "John Snow"; // OK
            m_age = 23; // OK
            //m_address = "897-78-723"; Compiler error
        }

        int get_contract_count() const {
            return contract_count;
        }
        
    private : 
        int contract_count;
};


Engineer::Engineer()
{
    contract_count = 0;
}

Engineer::Engineer(string_view fullname, int age, string_view address, int contract_count_param) :
          Person(fullname, age, address), contract_count(contract_count_param)
{
    cout << "Parametric constructor for Engineer called..." << endl;
}

ostream& operator << (ostream& out , const Engineer& operand){
     out << "Engineer [Full name: " << operand.get_full_name() <<
                    ", age: " << operand.get_age() << 
                    ", address: " << operand.get_address() <<
                    ", contract_count: " << operand.contract_count << "]";
    return out;   
}


Engineer::~Engineer()
{
}

#endif // ENGINEER_H
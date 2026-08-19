#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"

// Engineer is doing public inheritance
class Engineer : public Person {

    friend ostream& operator << (ostream& out , const Engineer& operand);

    public:
        Engineer();
        Engineer(string_view fullname, int age, string_view address, int contract_count_param);

        // For Copy Constructor
        Engineer(const Engineer &source);

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

Engineer::~Engineer()
{
    cout << "Engineer Destructor is called..." << endl;
}

/*
    1. First problem in this case is that we again access 
    the private variables of the Person class through the Engineer object (like "source.m_address").

    2. The second problem is that Engineer::Engineer(...) : Person(...) will create a temporary object for Person
    to initialize data through the Person constructor.
*/
/*
    Engineer::Engineer(const Engineer &source) 
        : Person(source.m_full_name, source.m_age, source.m_address), contract_count(source.contract_count)
    {
        cout << "Engineer Copy Constructor called..." << endl;
    }

    This is bad design!!!
*/


/*
    Proper Copy Constructor

    The compiler is smart enough to see that we are passing an engineering object to initialize the Person class.
    So the compiler will ignore the engineering part and initialize the Person class. 
*/
Engineer::Engineer(const Engineer &source) 
        : Person(source), contract_count(source.contract_count)
{
    cout << "Engineer Copy Constructor called..." << endl;
}


Engineer::Engineer()
{
    contract_count = 0;
}

Engineer::Engineer(string_view fullname, int age, string_view address, int contract_count_param) :
          Person(fullname, age, address), contract_count(contract_count_param)
{
    cout << "Constructor for Engineer called..." << endl;
}


ostream& operator << (ostream& out , const Engineer& operand) {
     out << "Engineer [Full name: " << operand.get_full_name() <<
                    ", age: " << operand.get_age() << 
                    ", address: " << operand.get_address() <<
                    ", contract_count: " << operand.contract_count << "]";
    return out;   
}

#endif // ENGINEER_H
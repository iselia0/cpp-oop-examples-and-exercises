#include <iostream>

using namespace std;

/*
    Inheritance

    10. Reused Symbols in Inheritance
*/

class Parent {
    public:
        Parent() = default;
        Parent(int member_var) : m_member_var(member_var) {}
        ~Parent() = default;

        void print_var() const {
            cout << "The value in Parent is: " << m_member_var << endl;
        }

    protected:
        int m_member_var = 10;
};


class Child : public Parent {
    public:
        Child() = default;
        Child(int member_var) : m_member_var(member_var) {}
        ~Child() = default;

        void print_var() const {
            cout << "The value in Child is:  " << m_member_var << endl;
        }

        // Here, the derived class Child will hide the member variable m_member_var of the parent class.
        void show_values() const {
            cout << "The value in Child is:  " << m_member_var << endl;
            cout << "The value in Parent is: " << Parent::m_member_var << endl;
        }

    private:
        int m_member_var = 1000;
};


int main() {

    // system("clear");

    Parent p1;
    p1.print_var();

    Child child;
    child.print_var();           // Calls the method in Child
    child.Parent::print_var();   // Calls the method in Parent

    cout << "--------" << endl;

    child.show_values();

    /*
        Are Reused Symbols in Inheritance recomended?
        
        Reusing symbols in inheritance can be recommended when 
        it makes sense in terms of code reusability, consistency, and polymorphism. 

        However, it's essential to carefully plan your class hierarchy, consider the principles of good design, 
        and be aware of potential issues like the fragile base class problem.
    */

}
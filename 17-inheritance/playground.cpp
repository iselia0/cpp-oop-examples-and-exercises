#include <iostream>
#include <string>

using namespace std;

class Employee{
    private:
        string name;
        int age;
        string position;
        float salary;
    
    public:
        Employee(){
            string name = "";
            int age = 0;
            string position = "";
            float salary = 0.0;
        }
        Employee (string nameP, int ageP, string positionP, float salaryP){
            this->name = nameP;
            this->age = ageP;
            this->position = positionP;
            this->salary = salaryP;
        }

        // Setters
        Employee *setName(string name){
            this->name = name;
            return this;
        }
        Employee *setAge(int age){
            this->age = age;
            return this;
        }
        Employee *setPosition(string position){
            this->position = position;
            return this;
        }
        Employee *setSalary(float salary){
            this->salary = salary;
            return this;
        }

        //Getters
        string getnName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        string getPosition(){
            return this->position;
        }

        float getSalary(){
            return this->salary;
        }

        //Methods
        void result(string name, int age, string position, float salary){
            setName(name);
            setAge(age);
            setPosition(position);
            setSalary(salary);
        }

        void employeeDetails(){
            cout << "Name of the Employee: " << this->getnName() << endl;
            cout << "Age of the Employee: " << this->getAge() << endl;
            cout << "Position of the Employee: " << this->getPosition() << endl;
            cout << "Salary of the Employee: " << this->getSalary() << endl;
        }
}; 

int main () {
    system("clear");

    Employee emp1("John", 25, "Manager", 2500.5);
    Employee emp2;

    emp2.setName("John");
    emp2.setAge(25);
    emp2.setPosition("Manager");
    emp2.setSalary(5000.0);
    emp2.getSalary();

    cout << "Employee 1 Details: " << endl;
    emp1.employeeDetails();
    cout << endl;

    cout << "Employee 2 Details: " << endl;
    emp2.employeeDetails();
    cout << endl;

}